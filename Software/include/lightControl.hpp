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

#ifndef LIGHT_CONTROL_HPP__
#define LIGHT_CONTROL_HPP__

#include "Arduino.h"
#include "FastLED.h"
#include "menu.hpp"
#include "musicVisualizer.hpp"
#include "fogMachine.hpp"
#include "buzzerControl.hpp"
#include "motorControl.hpp"

/// The LED strip is connected to pin 12 on the Arduino.
/// The LED strip illuminates the artwork on the box.
#define LIGHT_STRIP_PIN 12

/// The LED disc is connected to pin 11 on the Arduino.
/// The LED disc illuminates the skull.
#define LIGHT_SKULL_PIN 11

/// Number of LEDs on the LED strip.
#define LIGHT_STRIP_SIZE 27
/// Number of LEDs on the LED disc.
#define LIGHT_SKULL_SIZE 7

/// Time between two LED updates in ms.
/// If it's big the system wont be responsive.
#define LIGHT_UPDATE_RATE 20

/// The speed of dimming when turning
/// on or off the lighting.
#define LIGHT_FADE_RATE 2

/// It is used for the clap switch. It determinate
/// the time between two sample updates in ms.
#define SAMPLE_UPDATE_RATE 30

/// Initialize the LEDs.
void lightInit();

/// Update function for the lighting.
///
/// This function handles all the animations and
/// effects for the specific light modes. Also
/// it tries to recognise the clap pattern for
/// the clap switch.
void lightUpdate();

/// Turn on the lighting.
///
/// If you want to turn on the lights,
/// you have to call this function.
void lightOn();

/// Turn off the lighting.
///
/// If you want to turn off the lights,
/// you have to call this function.
void lightOff();

/// Toggle the lighting.
///
/// If you want to toggle the lights,
/// you have to call this function.
void lightToggle();

/// Update function for the rainbow mode.
///
/// Tis function handles the animations and lighting
/// for the rainbow mode. It has to be called by the
/// @ref lightUpdate function when the rainbow mode
/// is selected.
/// @note This function uses the [HSV](https://en.wikipedia.org/wiki/HSL_and_HSV) color space.
/// @note I used it because it is much easier to animate, than the regular RGB color space.
/// @see lightMode_t
void lightModeRainbowUpdate();

/// Update function for the candle mode.
///
/// Tis function handles the animations and lighting
/// for the candle mode. It has to be called by the
/// @ref lightUpdate function when the candle mode
/// is selected.
/// @note This function uses the [HSV](https://en.wikipedia.org/wiki/HSL_and_HSV) color space.
/// @note I used it because it is much easier to animate, than the regular RGB color space.
/// @see lightMode_t
void lightModeCandleUpdate();

/// Update function for the pulse mode.
///
/// Tis function handles the animations and lighting
/// for the pulse mode. It has to be called by the
/// @ref lightUpdate function when the pulse mode
/// is selected.
/// @note This function uses the [HSV](https://en.wikipedia.org/wiki/HSL_and_HSV) color space.
/// @note I used it because it is much easier to animate, than the regular RGB color space.
/// @see lightMode_t
void lightModePulseUpdate();

/// Update function for the music mode.
///
/// Tis function handles the animations and lighting
/// for the music mode. It has to be called by the
/// @ref lightUpdate function when the music mode
/// is selected.
/// @see lightMode_t
void lightModeMusicUpdate();

/// Update function for the komodo mode.
///
/// Tis function handles the animations and lighting
/// for the komodo mode. It has to be called by the
/// @ref lightUpdate function when the komodo mode
/// is selected. The name come from [Malcolm in the Middle](https://www.youtube.com/watch?v=97WTudZ5qzA)
/// @see lightMode_t
void lightModeKomodoUpdate();

/// Update function for the color mode.
///
/// Tis function handles the animations and lighting
/// for the color mode. It has to be called by the
/// @ref lightUpdate function when the color mode
/// is selected.
/// @see lightMode_t
void lightModeColorUpdate();


#endif