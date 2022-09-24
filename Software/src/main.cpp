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

ssd1306 display( 0x3C );

menu menuController( &display, &lightMenuItem );

configurationManager::configurationData_t configTree[] = {

    createData( lightMode ),
    createData( selectedColor ),
    createData( lightBrightness ),
    createData( buzzerEnabled ),
    createData( clapSwitchEnabled ),
    createData( fogMachineEnabled )

};

configurationManager config( configTree, ( sizeof( configTree ) / sizeof( configTree[0] ) ) );

void setup() {
  
    wdt_enable( WDTO_4S );

    Serial.begin( 115200 );

    if( !config.loadConfig() ){

        lightMode = DEFAULT_LIGHT_MODE;
        selectedColor = DEFAULT_SELECTED_COLOR;
        lightBrightness = DEFAULT_LIGHT_BRIGHTNESS;
        buzzerEnabled = DEFAULT_BUZZER_STATE;
        clapSwitchEnabled = DEFAULT_CLAP_SWITCH_STATE;
        fogMachineEnabled = DEFAULT_FOG_STATE;

        config.saveConfig();

    }

    if( !display.begin() ){

        Serial.println( F( "Display Error!" ) );
        
    }

    motorInit();

    pinMode( ENCODER_CLK, INPUT );
    pinMode( ENCODER_BTN, INPUT );
    pinMode( ENCODER_DATA, INPUT );

    attachInterrupt( digitalPinToInterrupt( ENCODER_CLK ), encoderISR, RISING );

    menuInit();

    lightInit();
    fogMachineInit();
        
}

void loop() {

    menuController.draw();
    encoderButtonUpdate();
    lightUpdate();
    fogMachineUpdate();

    wdt_reset();

}

void encoderISR(){

    if( frontState != FRONT_OPEN ){

        return;

    }

    //todo Ha csukva van, akkor ne vinnyogjon.
    if( digitalRead( ENCODER_CLK ) == digitalRead( ENCODER_DATA ) ){

        menuController.up();
        encoderRotateSound();
        
    }

    else{

        menuController.down();
        encoderRotateSound();
        
    }
  
}

long lastButtonPress = 0;
uint8_t buttonPressCntr = 0;
bool buttonPressed = false;

void encoderButtonUpdate(){

    if( digitalRead( ENCODER_BTN ) == 0 && !buttonPressed ){
        delay( 15 );
        buttonPressCntr++;
        lastButtonPress = millis();
        buttonPressed = true;
    }

    if( digitalRead( ENCODER_BTN ) == 1 ){

        buttonPressed = false;

    }

    if( ( ( millis() - lastButtonPress ) > 250 ) && buttonPressCntr ){

        switch( buttonPressCntr ){
            case 1:

                if( frontState == FRONT_OPEN ){

                    menuController.next();
                    config.saveConfig();
                    buttonClickSound();

                }

                else{

                    lightToggle();
                    turnOnMelody();

                }

            break;

            case 2:

                openCloseMelody();
                if( frontState == FRONT_OPEN ){

                    closeFront();

                }

                else{

                    openFront();

                }

            break;

        }
        
        buttonPressCntr = 0;
        
    }

}