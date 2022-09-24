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

menuItem::menuItem( const char* name_p ){

  name = name_p;
  
}

menu::menu( ssd1306* oled_p, menuItem* selectedItem_p ){

  selectedItem = selectedItem_p;
  oled = oled_p;
 
}

void menu::draw(){

    char textBuffer[ 20 ];

    if( oled == NULL ){
        return;
    }

    if( selectedItem == NULL ){
        return;
    }

    if( !changed ){
        return;
    }

    if( selectedItem -> drawFunc ){
        selectedItem -> drawFunc( oled );
        return;
    }

    oled -> clear();
    if( selectedItem -> up ){

        oled -> inverted = false;

        if( selectedItem -> up -> style == menuItem::INVERTED ){

            oled -> inverted = true;

        }

        oled -> cursorY = 4;
        oled -> cursorX = 8;
        oled -> print( (char*)" " );
        strcpy_P( textBuffer, selectedItem -> up -> name );
        oled -> print( textBuffer );

        if( selectedItem -> up -> selected ){

        oled -> cursorX = 118;
        oled -> writeCharacter( 0x82 );
        oled -> cursorX -=1;
        oled -> writeCharacter( 0x83 );

        }

    }
    
    oled -> inverted = false;

    oled -> cursorY = 14;
    oled -> cursorX = 0;
    oled -> print( (char*)">" );

    if( selectedItem -> style == menuItem::INVERTED ){

        oled -> inverted = true;

    }

    oled -> cursorX = 8;
    oled -> print( (char*)" " );
    strcpy_P( textBuffer, selectedItem -> name );
    oled -> print( textBuffer);

    if( selectedItem -> selected ){

        oled -> cursorX = 118;
        oled -> writeCharacter( 0x82 );
        oled -> cursorX -=1;
        oled -> writeCharacter( 0x83 );

    }

    if( selectedItem -> down ){

        oled -> inverted = false;

        if( selectedItem -> down -> style == menuItem::INVERTED ){

            oled -> inverted = true;

        }

        oled -> cursorY = 24;
        oled -> cursorX = 8;
        oled -> print( (char*)" " );
        strcpy_P( textBuffer, selectedItem -> down -> name );
        oled -> print( textBuffer );

        if( selectedItem -> down -> selected ){

        oled -> cursorX = 118;
        oled -> writeCharacter( 0x82 );
        oled -> cursorX -=1;
        oled -> writeCharacter( 0x83 );

        }       
    
    }

    oled -> update();
    
}

void menu::up(){

    if( selectedItem == NULL ){
        return;
    }

    if( selectedItem -> actionFunc ){

        selectedItem -> actionFunc( menuItem::UP );

    }

    if( selectedItem -> up ){

        if( selectedItem -> up -> selectable ){

            selectedItem = selectedItem -> up;

        }
        
    }

    changed = true;

}

void menu::down(){

    if( selectedItem == NULL ){
        return;
    }

    if( selectedItem -> actionFunc ){

        selectedItem -> actionFunc( menuItem::DOWN );

    }
    
    if( selectedItem -> down ){

        if( selectedItem -> down -> selectable ){
        
            selectedItem = selectedItem -> down;
        
        }
    
    }

    changed = true;

}

void menu::next(){

    if( selectedItem == NULL ){
        return;
    }

    if( selectedItem -> actionFunc ){

        selectedItem -> actionFunc( menuItem::NEXT );

    }

    if( selectedItem -> next ){
        
        selectedItem = selectedItem -> next;
        
    }

    changed = true;

}

//---- Main Menu ----//

void brightnessSelectFunction( enum menuItem::encoderState_t state ){

    if( state == menuItem::UP ){

        if( lightBrightness > 0 ){

            lightBrightness--;

        }

    }

    if( state == menuItem::DOWN ){

        if( lightBrightness < 100 ){

            lightBrightness++;

        }

    }

}

void brightnessSelectDrawFunction( ssd1306* oled ){

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


//---- Light mode menu content ----//

void rainbowMenuSelectFunction( enum menuItem::encoderState_t state ){

    if( state == menuItem::NEXT ){

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

    if( state == menuItem::NEXT ){

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

    if( state == menuItem::NEXT ){

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

    if( state == menuItem::NEXT ){

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

    if( state == menuItem::NEXT ){

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

    if( state == menuItem::NEXT ){

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

    if( state == menuItem::UP ){

        if( selectedColor > 0 ){

            selectedColor--;

        }

    }

    if( state == menuItem::DOWN ){

        if( selectedColor < 255 ){

            selectedColor++;

        }

    }

}

void colorSelectDrawFunction( ssd1306* oled ){

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

    if( state == menuItem::NEXT ){

        if( buzzerEnabled ){

            buzzerEnabled = false;

        }

        else{

            buzzerEnabled = true;

        }

        buzzerMenuItem.selected = buzzerEnabled;

    }

}

void clapMenuSelectedFunction( enum menuItem::encoderState_t state ){

    if( state == menuItem::NEXT ){

        if( clapSwitchEnabled ){

            clapSwitchEnabled = false;

        }

        else{

            clapSwitchEnabled = true;

        }

        clapMenuItem.selected = clapSwitchEnabled;

    }

}

void fogEnableMenuSelectedFunction( enum menuItem::encoderState_t state ){

    if( state == menuItem::NEXT ){

        if( fogMachineEnabled ){

            fogMachineEnabled = false;

        }

        else{

            fogMachineEnabled = true;

        }

        fogEnableMenuItem.selected = fogMachineEnabled;

    }

}


void fogTimerSelectFunction( enum menuItem::encoderState_t state ){

    if( state == menuItem::UP ){

        if( fogTimer > 0 ){

            fogTimer--;

        }

    }

    if( state == menuItem::DOWN ){

        if( fogTimer < 10 ){

            fogTimer++;

        }

    }

}

// 15min, 30min, 45min, 1h, 1.5h, 2h, 3h, 5h, 8h, 12h, 24h
const char fogTimer15minText[] PROGMEM = "15 min";
const char fogTimer30minText[] PROGMEM = "30 min";
const char fogTimer45minText[] PROGMEM = "45 min";
const char fogTimer1hourText[] PROGMEM = "1 hour";
const char fogTimer1p5hourText[] PROGMEM = "1.5 hour";
const char fogTimer2hourText[] PROGMEM = "2 hour";
const char fogTimer3hourText[] PROGMEM = "3 hour";
const char fogTimer5hourText[] PROGMEM = "5 hour";
const char fogTimer8hourText[] PROGMEM = "8 hour";
const char fogTimer12hourText[] PROGMEM = "12 hour";
const char fogTimer24hourText[] PROGMEM = "24 hour";

void fogTimerSelectDrawFunction( ssd1306* oled ){

    char textBuffer[ 20 ];

    float scale;

    scale = (float)fogTimer / 10.0 * 112.0;

    oled -> clear();
    oled -> inverted = false;
    oled -> cursorY = 8;
    oled -> cursorX = 8;
    oled -> print( (char*)"Fog timer - " );

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

enum lightMode_t lightMode = LIGHT_MODE_RAINBOW;

uint8_t selectedColor = 0;
uint8_t lightBrightness = 30;

bool buzzerEnabled = true;

bool clapSwitchEnabled = true;

bool fogMachineEnabled = true;

uint8_t fogTimer = 0;

//---- Main menu content ----//
const char mainMenuItemText[] PROGMEM = "Main menu ";
menuItem mainMenuItem( mainMenuItemText );

const char lightMenuItemText[] PROGMEM = "Light mode";
menuItem lightMenuItem( lightMenuItemText );

const char brightnessMenuItemText[] PROGMEM = "Brightness";
menuItem brightnessMenuItem( brightnessMenuItemText );

const char brightnessSelectItemText[] PROGMEM = "Brightness Select";
menuItem brightnessSelectItem( brightnessSelectItemText );

const char buzzerMenuItemText[] PROGMEM = "Buzzer";
menuItem buzzerMenuItem( buzzerMenuItemText );

const char clapMenuItemText[] PROGMEM = "Clap switch";
menuItem clapMenuItem( clapMenuItemText );

const char fogEnableMenuItemText[] PROGMEM = "Fog machine";
menuItem fogEnableMenuItem( fogEnableMenuItemText );

const char fogTimerMenuItemText[] PROGMEM = "Fog timer";
menuItem fogTimerMenuItem( fogTimerMenuItemText );

const char fogTimerSelectMenuItemText[] PROGMEM = "Fog timer select";
menuItem fogTimerSelectMenuItem( fogTimerSelectMenuItemText );

//---- Light mode menu content ----//
const char lightModeMenuItemText[] PROGMEM = "Light mode menu ";
menuItem lightModeMenuItem( lightModeMenuItemText );

const char rainbowModeMenuItemText[] PROGMEM = "Rainbow";
menuItem rainbowModeMenuItem( rainbowModeMenuItemText );

const char candleModeMenuItemText[] PROGMEM = "Candle";
menuItem candleModeMenuItem( candleModeMenuItemText );

const char pulseModeMenuItemText[] PROGMEM = "Pulse";
menuItem pulseModeMenuItem( pulseModeMenuItemText );

const char musicModeMenuItemText[] PROGMEM = "Music";
menuItem musicModeMenuItem( musicModeMenuItemText );

const char komodoModeMenuItemText[] PROGMEM = "Komodo-3000";
menuItem komodoModeMenuItem( komodoModeMenuItemText );

const char colorModeMenuItemText[] PROGMEM = "Color";
menuItem colorModeMenuItem( colorModeMenuItemText );

const char colorSelectMenuItemText[] PROGMEM = "Color Select";
menuItem colorSelectMenuItem( colorSelectMenuItemText );

