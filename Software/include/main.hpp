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

#ifndef MAIN_HPP__
#define MAIN_HPP__

#include "Arduino.h"
#include "globalResources.hpp"
#include "oled.hpp"
#include "menu.hpp"
#include "motorControl.hpp"
#include "lightControl.hpp"
#include "buzzerControl.hpp"
#include "configuration.hpp"
#include "fogMachine.hpp"
#include <avr/wdt.h>

/// The encoder button is connected to pin 2 on the Arduino.
#define ENCODER_BTN 2

/// The encoder data line is connected to pin 4 on the Arduino.
#define ENCODER_DATA 4

/// The encoder clock line is connected to pin 3 on the Arduino.
#define ENCODER_CLK 3

// The buzzer is connected to pin 9 on the Arduino.
#define BUZZER 9

//---- This section contains the default configuration for the first boot up ----//

/// Default value for the light mode.
#define DEFAULT_LIGHT_MODE          LIGHT_MODE_RAINBOW

/// Default value for the user selected color.
#define DEFAULT_SELECTED_COLOR      0

/// Default value for the brightness.
#define DEFAULT_LIGHT_BRIGHTNESS    30

/// By default the buzzer is enabled.
#define DEFAULT_BUZZER_STATE        true

/// By default the clap switch is enabled.
#define DEFAULT_CLAP_SWITCH_STATE   true

/// By default the fog machine is enabled.
#define DEFAULT_FOG_STATE           true

/// Interrupt service for the encoder rotation events.
void encoderISR();

/// This function handles the button press detection.
void encoderButtonUpdate();

#endif