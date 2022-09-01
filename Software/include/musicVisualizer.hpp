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

#ifndef MUSIC_MISUALIZER_HPP__
#define MUSIC_MISUALIZER_HPP__

#include "Arduino.h"

#define SOUND_MID A0
#define SOUND_HIGH A1
#define SOUND_LOW A3
#define SOUND_PEAK A2


class musicChannel{

public:
    musicChannel( int pin_p, float silentLimit_p );
    musicChannel( int pin_p, float silentLimit_p, float offset_p );
    musicChannel( int pin_p, float silentLimit_p, float offset_p, float avgSampleFilterBeta_p, float ampleFilterBeta_p );
    void update();
    void attachPeakFunction( void(*peakFunc_p)(void) );
    bool peak;
    float signal = 0.0;
    float signalMax = 0.0;


private:
    float silentLimit = 0.0;
    int pin = A0;
    float avgSample = 0.0;
    float sample = 0;
    float signalPrev = 0.0;
    float avgPeak = 0.0;
    float offset = 512.0;
    float avgSampleFilterBeta = 0.3;
    float ampleFilterBeta = 0.5;
    void(*peakFunc)(void) = NULL;

};

extern musicChannel low;
extern musicChannel mid;
extern musicChannel high;
extern musicChannel peak;

#endif