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

#define ENCODER_BTN 2
#define ENCODER_DATA 4
#define ENCODER_CLK 3

#define BUZZER 9
#define ENCODER_TONE_FREQENCY 5000
#define ENCODER_TONE_DURATION 20

#define DEFAULT_LIGHT_MODE          LIGHT_MODE_RAINBOW
#define DEFAULT_SELECTED_COLOR      0
#define DEFAULT_LIGHT_BRIGHTNESS    30
#define DEFAULT_BUZZER_STATE        true
#define DEFAULT_CLAP_SWITCH_STATE   true
#define DEFAULT_FOG_STATE           true


void encoderISR();
void encoderButtonUpdate();

#endif