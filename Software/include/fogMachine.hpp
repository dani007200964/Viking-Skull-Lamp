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


#ifndef FOG_MACHINE_HPP__
#define FOG_MACHINE_HPP__

#include "Arduino.h"
#include "menu.hpp"

/// The humidifier is connected to pin 6 on the Arduino
#define HUMIDIFIER_PIN 6

/// Humidifier turn on duration in ms. The humidifier will be turned on for this amount of time.
#define HUMIDIFIER_DURATION (unsigned long)15000

/// Humidifier cool down time. The humidifier has to be turned off for this amount of time before turning on again.
#define HUMIDIFIER_COOL_DOWN (unsigned long)30000

/// Initialize the fog machine( humidifier ).
void fogMachineInit();

/// Update the fog machine state.
///
/// This function should be called periodically.
/// It handles the state machine of the humidifier.
/// The humidifier module can not work for a long period of time
/// with dry tank, because it will overheat. We doesn't have any
/// sensor to monitor the liquid level in the tank, so I implemented
/// the simplest solution:
/// 1. The humidifier can be operated for a short amount of time.
/// It is specified in @ref HUMIDIFIER_DURATION
/// 2. After this time has elapsed it has to be turned off and let it
/// cool at least for some time. It is specified in @ref HUMIDIFIER_COOL_DOWN
/// 3. It can not turned on until the cool down time has expired.
///
/// Also if the humidifier is enabled for periodic humidification
/// we have to calculate when to start the automatic humidification next.
void fogMachineUpdate();

/// Enable the humidifier
///
/// This function turns on the humidifier if:
/// 1. The humidifier is turned off
/// 2. And the cool down time has expired.
void fogMachineEnable();

#endif