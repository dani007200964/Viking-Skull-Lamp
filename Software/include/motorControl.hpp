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

#ifndef MOTOR_CONTROL_HPP__
#define MOTOR_CONTROL_HPP__

#include "Arduino.h"
#include "globalResources.hpp"

/// The motor is connected to pin 5 on the Arduino.
#define MOTOR 5

/// The motor power can be set with this definition.
/// It's range is 0 - 255. 0 means no power 255 is max power.
#define MOTOR_PWM 240

/// The front endstop is connected to pin 7 on the Arduino.
#define FRONT_ENDSTOP 7

/// The back endstop is connected to pin 7 on the Arduino.
#define BACK_ENDSTOP 8

/// Maximum allowed time in ms, to open the front.
#define OPEN_TIMEOUT 2000

/// Maximum allowed time in ms, to close the front.
#define CLOSE_TIMEOUT 2000

/// States of the front panel.
enum frontState_t{

    FRONT_UNKNOWN,   ///< Front state is unknown( for example at startup ).
    FRONT_OPEN,      ///< Front is opened.
    FRONT_CLOSE      ///< Front is closed.

};

/// Initialize the motor.
void motorInit();

/// Open the font.
///
/// It will try to open the front panel.
/// @note If it fails and can't open the front in time, it will stop.
/// @see OPEN_TIMEOUT
void openFront();

/// Close the font.
///
/// It will try to close the front panel.
/// @note If it fails and can't close the front in time, it will stop.
/// @see CLOSE_TIMEOUT
void closeFront();

/// Store the state of the front panel.
extern enum frontState_t frontState;

#endif
