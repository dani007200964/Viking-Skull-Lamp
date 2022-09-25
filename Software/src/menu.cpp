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

#include "menu.hpp"

const char fogTimer15minText[] PROGMEM = "15 min";       ///< Fog timer text for 15 min
const char fogTimer30minText[] PROGMEM = "30 min";       ///< Fog timer text for 30 min
const char fogTimer45minText[] PROGMEM = "45 min";       ///< Fog timer text for 45 min
const char fogTimer1hourText[] PROGMEM = "1 hour";       ///< Fog timer text for 1 hour
const char fogTimer1p5hourText[] PROGMEM = "1.5 hour";   ///< Fog timer text for 1 hour 30 min
const char fogTimer2hourText[] PROGMEM = "2 hour";       ///< Fog timer text for 2 hour
const char fogTimer3hourText[] PROGMEM = "3 hour";       ///< Fog timer text for 3 hour
const char fogTimer5hourText[] PROGMEM = "5 hour";       ///< Fog timer text for 5 hour
const char fogTimer8hourText[] PROGMEM = "8 hour";       ///< Fog timer text for 8 hour
const char fogTimer12hourText[] PROGMEM = "12 hour";     ///< Fog timer text for 12 hour
const char fogTimer24hourText[] PROGMEM = "24 hour";     ///< Fog timer text for 24 hour

enum lightMode_t lightMode = LIGHT_MODE_RAINBOW;

uint8_t selectedColor = 0;

uint8_t lightBrightness = 30;

bool buzzerEnabled = true;

bool clapSwitchEnabled = true;

bool fogMachineEnabled = true;

uint8_t fogTimer = 0;

//---- Main menu content ----//
const char mainMenuItemText[] PROGMEM = "Main menu ";
const char lightMenuItemText[] PROGMEM = "Light mode";
const char brightnessMenuItemText[] PROGMEM = "Brightness";
const char brightnessSelectItemText[] PROGMEM = "Brightness Select";
const char buzzerMenuItemText[] PROGMEM = "Buzzer";
const char clapMenuItemText[] PROGMEM = "Clap switch";
const char fogEnableMenuItemText[] PROGMEM = "Fog machine";
const char fogTimerMenuItemText[] PROGMEM = "Fog timer";
const char fogTimerSelectMenuItemText[] PROGMEM = "Fog timer select";

menuItem mainMenuItem( mainMenuItemText );
menuItem lightMenuItem( lightMenuItemText );
menuItem brightnessMenuItem( brightnessMenuItemText );
menuItem brightnessSelectItem( brightnessSelectItemText );
menuItem buzzerMenuItem( buzzerMenuItemText );
menuItem clapMenuItem( clapMenuItemText );
menuItem fogEnableMenuItem( fogEnableMenuItemText );
menuItem fogTimerMenuItem( fogTimerMenuItemText );
menuItem fogTimerSelectMenuItem( fogTimerSelectMenuItemText );

//---- Light mode menu content ----//
const char lightModeMenuItemText[] PROGMEM = "Light mode menu ";
const char rainbowModeMenuItemText[] PROGMEM = "Rainbow";
const char candleModeMenuItemText[] PROGMEM = "Candle";
const char pulseModeMenuItemText[] PROGMEM = "Pulse";
const char musicModeMenuItemText[] PROGMEM = "Music";
const char komodoModeMenuItemText[] PROGMEM = "Komodo-3000";
const char colorModeMenuItemText[] PROGMEM = "Color";
const char colorSelectMenuItemText[] PROGMEM = "Color Select";

menuItem lightModeMenuItem( lightModeMenuItemText );
menuItem rainbowModeMenuItem( rainbowModeMenuItemText );
menuItem candleModeMenuItem( candleModeMenuItemText );
menuItem pulseModeMenuItem( pulseModeMenuItemText );
menuItem musicModeMenuItem( musicModeMenuItemText );
menuItem komodoModeMenuItem( komodoModeMenuItemText );
menuItem colorModeMenuItem( colorModeMenuItemText );
menuItem colorSelectMenuItem( colorSelectMenuItemText );


menuItem::menuItem( const char* name_p ){

    // Save it to the internal variable.
    name = name_p;

}

menu::menu( ssd1306* oled_p, menuItem* selectedItem_p ){

    // Save them to internal variable.
    selectedItem = selectedItem_p;
    oled = oled_p;

}

void menu::draw(){

    // To save some precious dynamic memory, the menu item
    // names are stored in the FLASH memory. But we can not
    // acces it directly. It is a limitation of the AVR
    // microcontrollers. To use them like a string, we have
    // to copy them to a buffer first. This is that buffer.
    char textBuffer[ 20 ];

    // If the display doesn't specified we have to return.
    if( oled == NULL ){
        return;
    }

    // If the selected item doesn't specified we have to return.
    if( selectedItem == NULL ){
        return;
    }

    // If the data on the display doesn't changed we finished.
    if( !changed ){
        return;
    }

    // Check if the draw function of the selected item has ben overriden.
    if( selectedItem -> drawFunc ){

        // If yes, execute overridden function, then return.
        selectedItem -> drawFunc( oled );
        return;

    }

    // First thins first. Clear the display.
    oled -> clear();

    // Check if the selected item has upper neighbour.
    if( selectedItem -> up ){

        // If it has, select the display mode according to
        // the neighbour's settings.
        oled -> inverted = false;

        if( selectedItem -> up -> style == menuItem::INVERTED ){

            oled -> inverted = true;

        }

        // Set cursor to line beginning.
        oled -> cursorY = 4;
        oled -> cursorX = 8;

        // Print an empty space. This placeholder is required for alignment.
        oled -> print( (char*)" " );

        // Copy the name of the neighbour's name to the textBuffer,
        // then print it to the display.
        strcpy_P( textBuffer, selectedItem -> up -> name );
        oled -> print( textBuffer );

        // Check if the neighbour is selected.
        if( selectedItem -> up -> selected ){

            // If yes, draw a filled circle at the end of the line.
            oled -> cursorX = 118;
            oled -> writeCharacter( 0x82 );
            oled -> cursorX -=1;
            oled -> writeCharacter( 0x83 );

        }

    }

    // Disable the inverted mode for the selected item's indicator.
    oled -> inverted = false;

    // Set cursor to line beginning.
    oled -> cursorY = 14;
    oled -> cursorX = 0;

    // Print the selected item's indicator.
    oled -> print( (char*)">" );

    // Select the display mode according to
    // the selected item's settings.
    if( selectedItem -> style == menuItem::INVERTED ){

        oled -> inverted = true;

    }

    // Set the position to match the alignment.
    oled -> cursorX = 8;
    oled -> print( (char*)" " );

    // Copy the name of the selected item's name to
    // the textBuffer, then print it to the display.
    strcpy_P( textBuffer, selectedItem -> name );
    oled -> print( textBuffer);

    // Check if the selected item is selected.
    // Yep I know at this point that the naming
    // would need more creativity.
    if( selectedItem -> selected ){

        // If yes, draw a filled circle at the end of the line.
        oled -> cursorX = 118;
        oled -> writeCharacter( 0x82 );
        oled -> cursorX -=1;
        oled -> writeCharacter( 0x83 );

    }

    // Check if the selected item has lower neighbour.
    if( selectedItem -> down ){

        // If it has, select the display mode according to
        // the neighbour's settings.
        oled -> inverted = false;

        if( selectedItem -> down -> style == menuItem::INVERTED ){

            oled -> inverted = true;

        }

        // Set cursor to line beginning.
        oled -> cursorY = 24;
        oled -> cursorX = 8;

        // Print an empty space. This placeholder is required for alignment.
        oled -> print( (char*)" " );

        // Copy the name of the neighbour's name to the textBuffer,
        // then print it to the display.
        strcpy_P( textBuffer, selectedItem -> down -> name );
        oled -> print( textBuffer );

        // Check if the neighbour is selected.
        if( selectedItem -> down -> selected ){

            // If yes, draw a filled circle at the end of the line.
            oled -> cursorX = 118;
            oled -> writeCharacter( 0x82 );
            oled -> cursorX -=1;
            oled -> writeCharacter( 0x83 );

        }

    }

    // Push the data from the display buffer to the display.
    oled -> update();

}

void menu::up(){

    // If the selected item doesn't specified we have to return.
    if( selectedItem == NULL ){
        return;
    }

    // Check if the action function of the selected item has ben overriden.
    if( selectedItem -> actionFunc ){

        // If yes, execute overridden function and pass the UP event.
        selectedItem -> actionFunc( menuItem::UP );

    }

    // Check if the selected item has upper neighbour.
    if( selectedItem -> up ){

        // If yes, check that it's selectable.
        if( selectedItem -> up -> selectable ){

            // If selectable, set the upper neighbour as selected
            selectedItem = selectedItem -> up;

        }

    }

    // Set the flag, because the content of the menu changed.
    changed = true;

}

void menu::down(){

    // If the selected item doesn't specified we have to return.
    if( selectedItem == NULL ){
        return;
    }

    // Check if the action function of the selected item has ben overriden.
    if( selectedItem -> actionFunc ){

        // If yes, execute overridden function and pass the DOWN event.
        selectedItem -> actionFunc( menuItem::DOWN );

    }

    // Check if the selected item has lower neighbour.
    if( selectedItem -> down ){

        // If yes, check that it's selectable.
        if( selectedItem -> down -> selectable ){

            // If selectable, set the lower neighbour as selected
            selectedItem = selectedItem -> down;

        }

    }

    // Set the flag, because the content of the menu changed.
    changed = true;

}

void menu::next(){

    // If the selected item doesn't specified we have to return.
    if( selectedItem == NULL ){
        return;
    }

    // Check if the action function of the selected item has ben overriden.
    if( selectedItem -> actionFunc ){

        // If yes, execute overridden function and pass the NEXT event.
        selectedItem -> actionFunc( menuItem::NEXT );

    }

    // Check if the selected item has upper neighbour.
    if( selectedItem -> next ){

        // If selectable, set the next neighbour as selected
        selectedItem = selectedItem -> next;

    }

    // Set the flag, because the content of the menu changed.
    changed = true;

}

/*
    __  ___      _          __  ___
   /  |/  /___ _(_)___     /  |/  /__  ____  __  __
  / /|_/ / __ `/ / __ \   / /|_/ / _ \/ __ \/ / / /
 / /  / / /_/ / / / / /  / /  / /  __/ / / / /_/ /
/_/  /_/\__,_/_/_/ /_/  /_/  /_/\___/_/ /_/\__,_/

*/
//---- Main Menu Content ----//

void brightnessSelectFunction( enum menuItem::encoderState_t state ){

    // If you see in front of you the inverted logic will be intuitive.

    // Check for UP event
    if( state == menuItem::UP ){

        // If we can, lower the brightness.
        if( lightBrightness > 0 ){

            lightBrightness--;

        }

    }

    // Check for DOWN event
    if( state == menuItem::DOWN ){

        // If we can, increment the brightness.
        if( lightBrightness < 100 ){

            lightBrightness++;

        }

    }

}

void brightnessSelectDrawFunction( ssd1306* oled ){

    // This section creates a slider.

    float scale;

    scale = (float)lightBrightness / 100.0 * 112.0;

    oled -> clear();
    oled -> inverted = false;
    oled -> cursorY = 8;
    oled -> cursorX = 10;
    oled -> print( (char*)"Brightness - " );
    oled -> print( lightBrightness );
    oled -> line( 8, 24, 120, 24 );
    oled -> cursorY = 20;
    oled -> cursorX = (uint8_t)scale + 4;
    oled -> writeCharacter( 0x80 );
    oled -> cursorX -= 1;
    oled -> writeCharacter( 0x81 );
    oled -> update();


}

/*
    __    _       __    __     __  ___          __
   / /   (_)___ _/ /_  / /_   /  |/  /___  ____/ /__
  / /   / / __ `/ __ \/ __/  / /|_/ / __ \/ __  / _ \
 / /___/ / /_/ / / / / /_   / /  / / /_/ / /_/ /  __/
/_____/_/\__, /_/ /_/\__/  /_/  /_/\____/\__,_/\___/
        /____/
*/
//---- Light mode menu content ----//

void rainbowMenuSelectFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Select Rainbow Mode and mark it as selected,
        // to make it visible in the list.
        rainbowModeMenuItem.selected    = true;
        candleModeMenuItem.selected     = false;
        pulseModeMenuItem.selected      = false;
        musicModeMenuItem.selected      = false;
        komodoModeMenuItem.selected     = false;
        colorModeMenuItem.selected      = false;

        lightMode = LIGHT_MODE_RAINBOW;

    }

}

void candleMenuSelectFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Select Candle Mode and mark it as selected,
        // to make it visible in the list.
        rainbowModeMenuItem.selected    = false;
        candleModeMenuItem.selected     = true;
        pulseModeMenuItem.selected      = false;
        musicModeMenuItem.selected      = false;
        komodoModeMenuItem.selected     = false;
        colorModeMenuItem.selected      = false;

        lightMode = LIGHT_MODE_CANDLE;

    }

}

void pulseMenuSelectFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Select Pulse Mode and mark it as selected,
        // to make it visible in the list.
        rainbowModeMenuItem.selected    = false;
        candleModeMenuItem.selected     = false;
        pulseModeMenuItem.selected      = true;
        musicModeMenuItem.selected      = false;
        komodoModeMenuItem.selected     = false;
        colorModeMenuItem.selected      = false;

        lightMode = LIGHT_MODE_PULSE;

    }

}

void musicMenuSelectFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Select Music Mode and mark it as selected,
        // to make it visible in the list.
        rainbowModeMenuItem.selected    = false;
        candleModeMenuItem.selected     = false;
        pulseModeMenuItem.selected      = false;
        musicModeMenuItem.selected      = true;
        komodoModeMenuItem.selected     = false;
        colorModeMenuItem.selected      = false;

        lightMode = LIGHT_MODE_MUSIC;

    }

}

void komodoMenuSelectFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Select Komodo Mode and mark it as selected,
        // to make it visible in the list.
        rainbowModeMenuItem.selected    = false;
        candleModeMenuItem.selected     = false;
        pulseModeMenuItem.selected      = false;
        musicModeMenuItem.selected      = false;
        komodoModeMenuItem.selected     = true;
        colorModeMenuItem.selected      = false;

        lightMode = LIGHT_MODE_KOMODO;

    }

}

void colorMenuSelectFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Select Color Mode and mark it as selected,
        // to make it visible in the list.
        rainbowModeMenuItem.selected    = false;
        candleModeMenuItem.selected     = false;
        pulseModeMenuItem.selected      = false;
        musicModeMenuItem.selected      = false;
        komodoModeMenuItem.selected     = false;
        colorModeMenuItem.selected      = true;

        lightMode = LIGHT_MODE_COLOR;

    }

}

void colorSelectFunction( enum menuItem::encoderState_t state ){

    // If you see in front of you the inverted logic will be intuitive.

    // Check for UP event
    if( state == menuItem::UP ){

        // If we can, lower the hue value.
        if( selectedColor > 0 ){

            selectedColor--;

        }

    }

    // Check for DOWN event
    if( state == menuItem::DOWN ){

        // If we can, increment the hue value.
        if( selectedColor < 255 ){

            selectedColor++;

        }

    }

}

void colorSelectDrawFunction( ssd1306* oled ){

    // This section creates a slider.

    float scale;

    scale = (float)selectedColor / 255.0 * 112.0;

    oled -> clear();
    oled -> inverted = false;
    oled -> cursorY = 8;
    oled -> cursorX = 20;
    oled -> print( (char*)"Color - " );
    oled -> print( selectedColor );
    oled -> line( 8, 24, 120, 24 );
    oled -> cursorY = 20;
    oled -> cursorX = (uint8_t)scale + 4;
    oled -> writeCharacter( 0x80 );
    oled -> cursorX -= 1;
    oled -> writeCharacter( 0x81 );
    oled -> update();


}

void buzzerMenuSelectedFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Toggle the buzzer state.
        if( buzzerEnabled ){

            buzzerEnabled = false;

        }

        else{

            buzzerEnabled = true;

        }

        // Mark the item to make it visible in the menu.
        buzzerMenuItem.selected = buzzerEnabled;

    }

}

void clapMenuSelectedFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Toggle the clap switch state.
        if( clapSwitchEnabled ){

            clapSwitchEnabled = false;

        }

        else{

            clapSwitchEnabled = true;

        }

        // Mark the item to make it visible in the menu.
        clapMenuItem.selected = clapSwitchEnabled;

    }

}

void fogEnableMenuSelectedFunction( enum menuItem::encoderState_t state ){

    // Check for NEXT event
    if( state == menuItem::NEXT ){

        // Toggle the fog machine state.
        if( fogMachineEnabled ){

            fogMachineEnabled = false;

        }

        else{

            fogMachineEnabled = true;

        }

        // Mark the item to make it visible in the menu.
        fogEnableMenuItem.selected = fogMachineEnabled;

    }

}


void fogTimerSelectFunction( enum menuItem::encoderState_t state ){

    // If you see in front of you the inverted logic will be intuitive.

    // Check for UP event
    if( state == menuItem::UP ){

        // If we can, lower the fog timer.
        if( fogTimer > 0 ){

            fogTimer--;

        }

    }

    // Check for DOWN event
    if( state == menuItem::DOWN ){

        // If we can, increment the fog timer.
        if( fogTimer < 10 ){

            fogTimer++;

        }

    }

}

void fogTimerSelectDrawFunction( ssd1306* oled ){

    // This section creates a slider.

    // Buffer for PROGMEM based text.
    char textBuffer[ 20 ];

    float scale;

    scale = (float)fogTimer / 10.0 * 112.0;

    oled -> clear();
    oled -> inverted = false;
    oled -> cursorY = 8;
    oled -> cursorX = 8;
    oled -> print( (char*)"Fog timer - " );

    // Copy the timer value from PROGMEM to the buffer to print it.
    switch( fogTimer ){

        case 0:
            strcpy_P( textBuffer, fogTimer15minText );
        break;

        case 1:
            strcpy_P( textBuffer, fogTimer30minText );
        break;

        case 2:
            strcpy_P( textBuffer, fogTimer45minText );
        break;

        case 3:
            strcpy_P( textBuffer, fogTimer1hourText );
        break;

        case 4:
            strcpy_P( textBuffer, fogTimer1p5hourText );
        break;

        case 5:
            strcpy_P( textBuffer, fogTimer2hourText );
        break;

        case 6:
            strcpy_P( textBuffer, fogTimer3hourText );
        break;

        case 7:
            strcpy_P( textBuffer, fogTimer5hourText );
        break;

        case 8:
            strcpy_P( textBuffer, fogTimer8hourText );
        break;

        case 9:
            strcpy_P( textBuffer, fogTimer12hourText );
        break;

        case 10:
            strcpy_P( textBuffer, fogTimer24hourText );
        break;

        default:

            strcpy_P( textBuffer, fogTimer15minText );
            fogTimer = 0;

        break;

    }

    oled -> print( textBuffer );

    oled -> line( 8, 24, 120, 24 );
    oled -> cursorY = 20;
    oled -> cursorX = (uint8_t)scale + 4;
    oled -> writeCharacter( 0x80 );
    oled -> cursorX -= 1;
    oled -> writeCharacter( 0x81 );
    oled -> update();


}

void menuInit(){

    //---- Main menu ----//
    mainMenuItem.down = &lightMenuItem;
    mainMenuItem.style = menuItem::INVERTED;
    mainMenuItem.selectable = false;

    lightMenuItem.up = &mainMenuItem;
    lightMenuItem.down = &brightnessMenuItem;
    lightMenuItem.next = &lightModeMenuItem;

    brightnessMenuItem.up = &lightMenuItem;
    brightnessMenuItem.down = &buzzerMenuItem;
    brightnessMenuItem.next = &brightnessSelectItem;

    brightnessSelectItem.next = &brightnessMenuItem;
    brightnessSelectItem.actionFunc = brightnessSelectFunction;
    brightnessSelectItem.drawFunc = brightnessSelectDrawFunction;


    buzzerMenuItem.up = &brightnessMenuItem;
    buzzerMenuItem.down = &clapMenuItem;
    buzzerMenuItem.selected = buzzerEnabled;
    buzzerMenuItem.actionFunc = buzzerMenuSelectedFunction;

    clapMenuItem.up = &buzzerMenuItem;
    clapMenuItem.down = &fogEnableMenuItem;
    clapMenuItem.selected = clapSwitchEnabled;
    clapMenuItem.actionFunc = clapMenuSelectedFunction;

    fogEnableMenuItem.up = &clapMenuItem;
    fogEnableMenuItem.down = &fogTimerMenuItem;
    fogEnableMenuItem.selected = fogMachineEnabled;
    fogEnableMenuItem.actionFunc = fogEnableMenuSelectedFunction;

    fogTimerMenuItem.up = &fogEnableMenuItem;
    fogTimerMenuItem.next = &fogTimerSelectMenuItem;

    fogTimerSelectMenuItem.next = &fogTimerMenuItem;
    fogTimerSelectMenuItem.actionFunc = fogTimerSelectFunction;
    fogTimerSelectMenuItem.drawFunc = fogTimerSelectDrawFunction;

    //---- Light mode menu ----//
    lightModeMenuItem.style = menuItem::INVERTED;
    lightModeMenuItem.down = &rainbowModeMenuItem;
    lightModeMenuItem.next = &lightMenuItem;

    rainbowModeMenuItem.up = &lightModeMenuItem;
    rainbowModeMenuItem.down = &candleModeMenuItem;
    rainbowModeMenuItem.actionFunc = rainbowMenuSelectFunction;

    candleModeMenuItem.up = &rainbowModeMenuItem;
    candleModeMenuItem.down = &pulseModeMenuItem;
    candleModeMenuItem.actionFunc = candleMenuSelectFunction;

    pulseModeMenuItem.up = &candleModeMenuItem;
    pulseModeMenuItem.down = &musicModeMenuItem;
    pulseModeMenuItem.actionFunc = pulseMenuSelectFunction;

    musicModeMenuItem.up = &pulseModeMenuItem;
    musicModeMenuItem.down = &komodoModeMenuItem;
    musicModeMenuItem.actionFunc = musicMenuSelectFunction;

    komodoModeMenuItem.up = &musicModeMenuItem;
    komodoModeMenuItem.down = &colorModeMenuItem;
    komodoModeMenuItem.actionFunc = komodoMenuSelectFunction;

    colorModeMenuItem.up = &komodoModeMenuItem;
    colorModeMenuItem.next = &colorSelectMenuItem;
    colorModeMenuItem.actionFunc = colorMenuSelectFunction;

    colorSelectMenuItem.next = &colorModeMenuItem;
    colorSelectMenuItem.actionFunc = colorSelectFunction;
    colorSelectMenuItem.drawFunc = colorSelectDrawFunction;

    switch( lightMode ){

        case LIGHT_MODE_RAINBOW:
            rainbowModeMenuItem.selected    = true;
        break;

        case LIGHT_MODE_CANDLE:
            candleModeMenuItem.selected     = true;
        break;

        case LIGHT_MODE_PULSE:
            pulseModeMenuItem.selected      = true;
        break;

        case LIGHT_MODE_MUSIC:
            musicModeMenuItem.selected      = true;
        break;

        case LIGHT_MODE_KOMODO:
            komodoModeMenuItem.selected     = true;
        break;

        case LIGHT_MODE_COLOR:
            colorModeMenuItem.selected      = true;
        break;

    }

}
