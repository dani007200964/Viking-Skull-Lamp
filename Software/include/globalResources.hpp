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

#ifndef GLOBAL_RESOURCES_HPP__
#define GLOBAL_RESOURCES_HPP__

#include "Arduino.h"
#include "oled.hpp"
#include "menu.hpp"
#include "configuration.hpp"

#define OLED_ADDRESS 0x3C

/// Object for the display.
///
/// This object can control a 128 x 32 pixel oled
/// display which have an SSD1306 display driver.
/// The address is configurable in the
/// @ref OLED_ADDRESS macro.
/// @see OLED_ADDRESS
extern ssd1306 display;

/// Object for the menu.
///
/// This object handles all the logic behind the
/// menu system. It uses the @ref display object
/// as output and the default selected menu item
/// is @ref lightMenuItem
extern menu menuController;

/// Object for configuration saving and loading.
///
/// This object handles the saving and the loading 
/// loading of the configuration data. It uses the
/// @ref configTree array, which contains all the
/// configuration associated variables.
extern configurationManager config;

#endif
