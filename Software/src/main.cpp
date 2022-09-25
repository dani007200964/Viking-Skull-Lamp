/*
 * Created on May 28 2022
 *
 * Copyright (c) 2022 - Daniel Hajnal
 * hajnal.daniel96@gmail.com
 * This file is part of the Viking Skull Lamp project.
 * Modified 2022.06.27
*/

/*
MIT License
Copyright (c) 2022 Daniel Hajnal
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "main.hpp"

/// Object for the display.
///
/// This object can control a 128 x 32 pixel oled
/// display whisch have an SSD1306 display driver.
/// The address is configurable in the
/// @ref OLED_ADDRESS macro.
/// @see OLED_ADDRESS
ssd1306 display( OLED_ADDRESS );

/// Object for the menu.
///
/// This object handles all the logic behind the
/// menu system. It uses the @ref display object
/// as output and the default selected menu item
/// is @ref lightMenuItem
menu menuController( &display, &lightMenuItem );

/// This array contains all the variables,
/// that required for configuring the device
configurationManager::configurationData_t configTree[] = {

    createData( lightMode ),
    createData( selectedColor ),
    createData( lightBrightness ),
    createData( buzzerEnabled ),
    createData( clapSwitchEnabled ),
    createData( fogMachineEnabled )

};

/// Object for configuration saving and loading.
///
/// This object handles the saving and the loading 
/// loading of the configuration data. It uses the
/// @ref configTree array, which contains all the
/// configuration associated variables.
configurationManager config( configTree, ( sizeof( configTree ) / sizeof( configTree[0] ) ) );

/// Last system time when the button was pressed.
long lastButtonPress = 0;

/// Counts how many button press was detected in a period.
uint8_t buttonPressCntr = 0;

/// Flag for button press detection.
bool buttonPressed = false;

/// Device initialization section after reset.
void setup() {
  
    // Just in case we enable the watchdog with 4-sec timeout.
    wdt_enable( WDTO_4S );

    // Initialize the Serial port.
    Serial.begin( 115200 );

    // Try to load the configuration from the EEPROM.
    if( !config.loadConfig() ){

        // If the configuration loading is not succesful,
        // we set the config variables to the default values.
        lightMode = DEFAULT_LIGHT_MODE;
        selectedColor = DEFAULT_SELECTED_COLOR;
        lightBrightness = DEFAULT_LIGHT_BRIGHTNESS;
        buzzerEnabled = DEFAULT_BUZZER_STATE;
        clapSwitchEnabled = DEFAULT_CLAP_SWITCH_STATE;
        fogMachineEnabled = DEFAULT_FOG_STATE;

        // Also we try to save the config again.
        config.saveConfig();

    }

    // Try to initialize the oled display.
    if( !display.begin() ){

        // If we can't, we print the error.
        Serial.println( F( "Display Error!" ) );
        
    }

    // Initialize motor logic.
    motorInit();

    // Initialize encoder pins.
    pinMode( ENCODER_CLK, INPUT );
    pinMode( ENCODER_BTN, INPUT );
    pinMode( ENCODER_DATA, INPUT );

    // For encoder rotation detection we use an interrupt,
    // so we have to register that to the @ref ENCODER_CLK pin.
    // Every time a rising endge arrives ti @ref ENCODER_CLK pin,
    // the @ref encoderISR function will be called.
    attachInterrupt( digitalPinToInterrupt( ENCODER_CLK ), encoderISR, RISING );

    // Initialize menu system.
    menuInit();

    // Initialize lighting.
    lightInit();

    // Initialize the humidifier.
    fogMachineInit();
        
}

/// This is the infinite loop of
/// the code. Every periodic task
/// should be placed here.
void loop() {

    // Update menu data.
    menuController.draw();

    // Update button handler.
    encoderButtonUpdate();

    // Update lighting effects.
    lightUpdate();

    // Update the humidifier module.
    fogMachineUpdate();

    // Feed the watchdog.
    wdt_reset();

}

void encoderISR(){

    // We only allowed to use the menu,
    // when the front panel is opened.
    if( frontState != FRONT_OPEN ){

        return;

    }

    // We have to detect the direction of the rotation.
    // If we rotate it to one direction the state of the
    // data line and the clock line always be equal. If we
    // change direction they always be different.
    if( digitalRead( ENCODER_CLK ) == digitalRead( ENCODER_DATA ) ){

        menuController.up();
        encoderRotateSound();
        
    }

    else{

        menuController.down();
        encoderRotateSound();
        
    }
  
}

void encoderButtonUpdate(){

    // The encoder button uses inverted logic. If it is pressed
    // the output of the button will be low.
    if( digitalRead( ENCODER_BTN ) == 0 && !buttonPressed ){

        // A tiny delay required to debounce the signal.
        delay( 15 );

        // Increment the buttonPressCntr.
        buttonPressCntr++;

        // Save system time.
        lastButtonPress = millis();

        // Set the flag to true. It is required for event generation.
        buttonPressed = true;
    }

    // Check if the button was released.
    if( digitalRead( ENCODER_BTN ) == 1 ){

        // Reset the flag.
        buttonPressed = false;

    }

    // To detect multiple button presses we have to be quick. The time between
    // two button presses should be less than 250ms. Otherwise it will be detected
    // as a single press.
    if( ( ( millis() - lastButtonPress ) > 250 ) && buttonPressCntr ){

        // Decide action according to the number of the button pressed.
        switch( buttonPressCntr ){

            // Button pressed once.
            case 1:

                // If the front is opened we use the button to navigate
                // in the menu. Also we save the config with every button
                // press. If there are no changes in the configuration
                // data it will skip the writing anyway.
                if( frontState == FRONT_OPEN ){

                    menuController.next();
                    config.saveConfig();
                    buttonClickSound();

                }

                // If the front is closed we use the button to turn on or
                // off the lighting.
                else{

                    lightToggle();
                    turnOnMelody();

                }

            break;

            // Button pressed twice.
            case 2:

                // Open or close the front depending on it's state.
                openCloseMelody();
                if( frontState == FRONT_OPEN ){

                    closeFront();

                }

                else{

                    openFront();

                }

            break;

        }
        
        // Reset the buttonPressCntr variable for the next round.
        buttonPressCntr = 0;
        
    }

}