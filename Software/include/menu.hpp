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

#ifndef MENU_HPP__
#define MENU_HPP__

#include "Arduino.h"
#include "oled.hpp"
#include <avr/pgmspace.h>

/// Menu Item Class
///
/// This object describes an element in the menu.
/// An element usually just a line of text.
/// In the menu the elements are placed like a list.
/// In normal case an element have an upper neighbor
/// and a lower neighbor. If you scroll through the
/// menu the selection system will use the neighborhood
/// of the item to draw the upper and lower menus.
/// Also there is a special neighbor called next. It will
/// be selected when we press the button on the item.
/// There are some other parameters but they will be
/// described below.
class menuItem{

public:

    /// Used for @ref actionFunc to pass the event
    /// as an argument.
    enum encoderState_t{
        NEXT, ///< Encoder button pressed
        UP,   ///< Encoder rotated up
        DOWN  ///< Encoder rotated down
    };

    /// Describes the style of the item drawing.
    enum menuStyle_t{
        NORMAL,   ///< The active pixel is lit, the inactive is black.
        INVERTED  ///< The active pixel is black, the inactive is lit.
    };

    /// Constructor.
    /// @param name_p It is a pointer to a string. This string will be displayed in the menu.
    /// @warning The source of __name_p__ argument has to be placed in PROGMEM!
    menuItem( const char* name_p );

    /// Pointer to the upper neighbor.
    menuItem* up = NULL;

    /// Pointer to the lower neighbor.
    menuItem* down = NULL;

    /// Pointer to the next neighbor.
    menuItem* next = NULL;

    /// If set, the item won't be selectable.
    /// That means the scrolling will stop before
    /// this item, and you can not reach it.
    bool selectable = true;

    /// If set, a filled circle will appear on the right side,
    /// next to the item name. It can be used to indicate that
    /// something has been activated.
    bool selected = false;

    /// Menu style variable. By default it is set to NORMAL.
    enum menuStyle_t style = NORMAL;

    /// Function pointer to override the button action behaviour
    ///
    /// If it's not NULL, the menu controller will call this function
    /// instead of the regular menu behaviour if any interaction happen
    /// to this item.
    void(*actionFunc)( enum encoderState_t state ) = NULL;

    /// Function pointer to override the drawing behaviour
    ///
    /// If it's not NULL, the menu controller will call this function
    /// instead of the regular drawing behaviour. It can be useful when
    /// you nedd to control or set something.
    void(*drawFunc)( ssd1306* oled ) = NULL;

    /// It is a pointer to a string. This string will be displayed in the menu.
    /// @warning The source has to be placed in PROGMEM!
    const char* name = NULL;

private:

};

/// Menu Controller Class
///
/// This class handles the menu drawing, item scrolling,
/// behaviour overrides and lot more.
class menu{

public:

    /// Constructor
    /// @param oled_p Pointer to a display controller object.
    /// @param selectedItem_p Pointer to the default selected item. This item will be selected after startup.
    menu( ssd1306* oled_p, menuItem* selectedItem_p );

    /// Redraw the menu to the display.
    /// @note It will only redraw the content of the display when something actually changes.
    void draw();

    /// Step te menu upwards if possible.
    void up();

    /// Step te menu downwards if possible.
    void down();

    /// Enter to the next menu if possible.
    void next();

private:

    /// Pointer to the selected menu item.
    menuItem* selectedItem = NULL;

    /// Pointer to the display controller object.
    ssd1306* oled = NULL;

    /// Flag that shows if the content of the display is changed.
    bool changed = true;

};

/// Lost of the different lighting effects
enum lightMode_t{
    LIGHT_MODE_RAINBOW,
    LIGHT_MODE_CANDLE,
    LIGHT_MODE_PULSE,
    LIGHT_MODE_MUSIC,
    LIGHT_MODE_KOMODO,
    LIGHT_MODE_COLOR,
};

/// It will store the user selected light mode.
extern enum lightMode_t lightMode;

/// It will store the user selected color.
extern uint8_t selectedColor;

/// It will store the user selected brightness.
extern uint8_t lightBrightness;

/// It will store the user selected state of the buzzer.
extern bool buzzerEnabled;

/// It will store the user selected state of the clap switch.
extern bool clapSwitchEnabled;

/// It will store the user selected state of the fog machine.
extern bool fogMachineEnabled;

/// It will store the user selected humidification period.
/// * 0  -> 15 min
/// * 1  -> 30 min
/// * 2  -> 45 min
/// * 3  -> 1 hour
/// * 4  -> 1 hour 30 min
/// * 5  -> 2 hour
/// * 6  -> 3 hour
/// * 7  -> 5 hour
/// * 8  -> 8 hour
/// * 9  -> 12 hour
/// * 10 -> 24 hour
/// @todo It looks like I haven't added this to the configuration yet. Maybe I should?
extern uint8_t fogTimer;

/// Initialize the menu system.
/// @todo Maybe a menu map can visualize the behaviour of the ton of settings. It's a huge graph, yED could do that I think.
void menuInit();

/*
    ____       __                _                                               _     __         
   / __ )___  / /_  ____ __   __(_)___  __  _______   ____ _   _____  __________(_)___/ /__  _____
  / __  / _ \/ __ \/ __ `/ | / / / __ \/ / / / ___/  / __ \ | / / _ \/ ___/ ___/ / __  / _ \/ ___/
 / /_/ /  __/ / / / /_/ /| |/ / / /_/ / /_/ / /     / /_/ / |/ /  __/ /  / /  / / /_/ /  __(__  ) 
/_____/\___/_/ /_/\__,_/ |___/_/\____/\__,_/_/      \____/|___/\___/_/  /_/  /_/\__,_/\___/____/  
                                                                                                  
*/                                                                                                                                

/// Behaviour override for brightness selection.
///
/// This function will be called by the @ref brightnessSelectItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void brightnessSelectFunction( enum menuItem::encoderState_t state );

/// Draw override for brightness selection.
///
/// This function will be called by the @ref brightnessSelectItem
/// when it's content has to be drawn.
/// @param oled Pointer to the display controller object. The function acces the display through this pointer.
void brightnessSelectDrawFunction( ssd1306* oled );

/// Behaviour override for buzzer menu.
///
/// This function will be called by the @ref buzzerMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void buzzerMenuSelectedFunction( enum menuItem::encoderState_t state );

/// Behaviour override for clap menu.
///
/// This function will be called by the @ref clapMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void clapMenuSelectedFunction( enum menuItem::encoderState_t state );

/// Behaviour override for fog timer setting menu.
///
/// This function will be called by the @ref fogTimerSelectMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void fogTimerSelectFunction( enum menuItem::encoderState_t state );

/// Draw override for fog timer setting.
///
/// This function will be called by the @ref fogTimerSelectMenuItem
/// when it's content has to be drawn.
/// @param oled Pointer to the display controller object. The function acces the display through this pointer.
void fogTimerSelectDrawFunction( ssd1306* oled );

/// Behaviour override for rainbow menu select.
///
/// This function will be called by the @ref rainbowModeMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void rainbowMenuSelectFunction( enum menuItem::encoderState_t state );

/// Behaviour override for candle menu select.
///
/// This function will be called by the @ref candleModeMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void candleMenuSelectFunction( enum menuItem::encoderState_t state );

/// Behaviour override for pulse menu select.
///
/// This function will be called by the @ref pulseModeMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void pulseMenuSelectFunction( enum menuItem::encoderState_t state );

/// Behaviour override for music menu select.
///
/// This function will be called by the @ref musicModeMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void musicMenuSelectFunction( enum menuItem::encoderState_t state );

/// Behaviour override for komodo menu select.
///
/// This function will be called by the @ref komodoModeMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void komodoMenuSelectFunction( enum menuItem::encoderState_t state );

/// Behaviour override for color mode menu.
///
/// This function will be called by the @ref colorModeMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void colorMenuSelectFunction( enum menuItem::encoderState_t state );

/// Behaviour override for color select menu.
///
/// This function will be called by the @ref colorSelectMenuItem
/// when it is selected and any interaction happens with the menu.
/// @param state Event, that describes what kind of interaction happened.
void colorSelectFunction( enum menuItem::encoderState_t state );

/// Draw override for color select menu.
///
/// This function will be called by the @ref colorSelectMenuItem
/// when it's content has to be drawn.
/// @param oled Pointer to the display controller object. The function acces the display through this pointer.
void colorSelectDrawFunction( ssd1306* oled );


/*
    __  ___      _          __  ___                
   /  |/  /___ _(_)___     /  |/  /__  ____  __  __
  / /|_/ / __ `/ / __ \   / /|_/ / _ \/ __ \/ / / /
 / /  / / /_/ / / / / /  / /  / /  __/ / / / /_/ / 
/_/  /_/\__,_/_/_/ /_/  /_/  /_/\___/_/ /_/\__,_/  
                                                   
*/
//---- Main menu content ----//

/// Main Menu text item.
extern menuItem mainMenuItem;

/// Light Menu item
extern menuItem lightMenuItem;

/// Brightness Menu item
extern menuItem brightnessMenuItem;

/// Brightness Select item
extern menuItem brightnessSelectItem;

/// Buzzer Menu item
extern menuItem buzzerMenuItem;

/// Clap Menu item
extern menuItem clapMenuItem;

/// Fog Enable Menu item
extern menuItem fogEnableMenuItem;

/// Fog Timer Menu item
extern menuItem fogTimerMenuItem;

/// Brightness Timer Select item
extern menuItem fogTimerSelectMenuItem;

/*
    __    _       __    __     __  ___          __   
   / /   (_)___ _/ /_  / /_   /  |/  /___  ____/ /__ 
  / /   / / __ `/ __ \/ __/  / /|_/ / __ \/ __  / _ \
 / /___/ / /_/ / / / / /_   / /  / / /_/ / /_/ /  __/
/_____/_/\__, /_/ /_/\__/  /_/  /_/\____/\__,_/\___/ 
        /____/                                       
*/
//---- Light mode menu content ----//

/// Light Mode Menu item
extern menuItem lightModeMenuItem;

/// Rainbow Mode Menu item
extern menuItem rainbowModeMenuItem;

/// Candle Mode Menu item
extern menuItem candleModeMenuItem;

/// Pulse Mode Menu item
extern menuItem pulseModeMenuItem;

/// Music Mode Menu item
extern menuItem musicModeMenuItem;

/// Komodo Mode Menu item
extern menuItem komodoModeMenuItem;

/// Color Mode Menu item
extern menuItem colorModeMenuItem;

/// Color Select item
extern menuItem colorSelectMenuItem;

#endif
