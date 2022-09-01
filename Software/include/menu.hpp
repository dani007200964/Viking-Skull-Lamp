/*
 * Created on May 28 2022
 *
 * Copyright (c) 2022 - Daniel Hajnal
 * hajnal.daniel96@gmail.com
 * This file is part of the Shellminator project.
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

#ifndef MENU_HPP__
#define MENU_HPP__

#include "Arduino.h"
#include "oled.hpp"
#include <avr/pgmspace.h>

class menuItem{

public:

    enum encoderState_t{
        NEXT,
        UP,
        DOWN
    };

    enum menuStyle_t{
        NORMAL,
        INVERTED
    };

    menuItem( const char* name_p );
    menuItem* up = NULL;
    menuItem* down = NULL;
    menuItem* next = NULL;
    bool selectable = true;
    bool selected = false;

    enum menuStyle_t style = NORMAL;

    void(*actionFunc)( enum encoderState_t state ) = NULL;
    void(*drawFunc)( ssd1306* oled ) = NULL;

    const char* name = NULL;

private:
  
};

class menu{

public:
    menu( ssd1306* oled_p, menuItem* selectedItem_p );
    void draw();
    void up();
    void down();
    void next();

private:
    menuItem* selectedItem = NULL;
    ssd1306* oled = NULL;
    bool changed = true;
  
};

enum lightMode_t{
    LIGHT_MODE_RAINBOW,
    LIGHT_MODE_CANDLE,
    LIGHT_MODE_PULSE,
    LIGHT_MODE_MUSIC,
    LIGHT_MODE_KOMODO,
    LIGHT_MODE_COLOR,
};

void menuInit();

void brightnessSelectFunction( enum menuItem::encoderState_t state );
void brightnessSelectDrawFunction( ssd1306* oled );

void buzzerMenuSelectedFunction( enum menuItem::encoderState_t state );
void clapMenuSelectedFunction( enum menuItem::encoderState_t state );

void fogTimerSelectFunction( enum menuItem::encoderState_t state );
void fogTimerSelectDrawFunction( ssd1306* oled );

void rainbowMenuSelectFunction( enum menuItem::encoderState_t state );
void candleMenuSelectFunction( enum menuItem::encoderState_t state );
void pulseMenuSelectFunction( enum menuItem::encoderState_t state );
void musicMenuSelectFunction( enum menuItem::encoderState_t state );
void komodoMenuSelectFunction( enum menuItem::encoderState_t state );
void colorMenuSelectFunction( enum menuItem::encoderState_t state );
void colorSelectFunction( enum menuItem::encoderState_t state );
void colorSelectDrawFunction( ssd1306* oled );

extern enum lightMode_t lightMode;

extern uint8_t selectedColor;
extern uint8_t lightBrightness;

extern bool buzzerEnabled;

extern bool clapSwitchEnabled;

extern bool fogMachineEnabled;

extern uint8_t fogTimer; // 15min, 30min, 45min, 1h, 1.5h, 2h, 3h, 5h, 8h, 12h, 24h
extern long fogTimerInMS;

//---- Main menu content ----//
extern menuItem mainMenuItem;
extern menuItem lightMenuItem;
extern menuItem brightnessMenuItem;
extern menuItem brightnessSelectItem;
extern menuItem buzzerMenuItem;
extern menuItem clapMenuItem;
extern menuItem fogEnableMenuItem;
extern menuItem fogTimerMenuItem;
extern menuItem fogTimerSelectMenuItem;

//---- Light mode menu content ----//
extern menuItem lightModeMenuItem;
extern menuItem rainbowModeMenuItem;
extern menuItem candleModeMenuItem;
extern menuItem pulseModeMenuItem;
extern menuItem musicModeMenuItem;
extern menuItem komodoModeMenuItem;
extern menuItem colorModeMenuItem;
extern menuItem colorSelectMenuItem;


#endif