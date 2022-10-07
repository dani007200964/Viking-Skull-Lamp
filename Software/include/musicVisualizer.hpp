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

#ifndef MUSIC_MISUALIZER_HPP__
#define MUSIC_MISUALIZER_HPP__

#include "Arduino.h"

/// The mid-range filter is connected to pin A0 on the Arduino.
#define SOUND_MID A0

/// The high-range filter is connected to pin A1 on the Arduino.
#define SOUND_HIGH A1

/// The low-range filter is connected to pin A3 on the Arduino.
#define SOUND_LOW A3

/// The peak-detector is connected to pin A2 on the Arduino.
#define SOUND_PEAK A2

/// This object is used to process audio data.
///
/// It is basically an advanced peak detector. It detects
/// the noise floor dynamically to adjust it to the environment.
class musicChannel{

public:
    /// Constructor.
    /// @param pin_p Analog input pin.
    /// @param silentLimit_p Silent limit level. It depends on the exact type of the microphone.
    musicChannel( int pin_p, float silentLimit_p );

    /// Constructor.
    /// @param pin_p Analog input pin.
    /// @param silentLimit_p Silent limit level. It depends on the exact type of the microphone.
    /// @param offset_p ADC offset. It is used when the ADC data is shifted. For example to half supply.
    musicChannel( int pin_p, float silentLimit_p, float offset_p );

    /// Constructor.
    /// @param pin_p Analog input pin.
    /// @param silentLimit_p Silent limit level. It depends on the exact type of the microphone.
    /// @param offset_p ADC offset. It is used when the ADC data is shifted. For example to half supply.
    /// @param avgSampleFilterBeta_p Filter coefficient for the average sample data. It used by a complementary-filter. Range [ 0.0 - 1.0 ]
    /// @param sampleFilterBeta_p Filter coefficient for the sample data. It used by a complementary-filter. Range [ 0.0 - 1.0 ]
    musicChannel( int pin_p, float silentLimit_p, float offset_p, float avgSampleFilterBeta_p, float sampleFilterBeta_p );

    /// Update function
    ///
    /// This function has to be called periodically with fixed timing.
    /// @note I tested it with various sampling times, in my opinion 30ms is a good choice.
    void update();

    /// Attach a function to every peak event.
    ///
    /// You can attach a function to every peak event. It can be useful
    /// when you want to respond very fast to a peak.
    /// @param peakFunc_p Function that will be called when a peak event occurs.
    void attachPeakFunction( void(*peakFunc_p)(void) );

    /// Flag, that indicates a peak event.
    bool peak;

    /// The filtered signal will be stored in this variable.
    float signal = 0.0;

    /// The maximum level of the signal is stored in this variable.
    /// Imagine it like a digital Vu meters output.
    float signalMax = 0.0;


private:

    /// Silent limit. If the signal is less then this value, it wont react to peaks.
    /// It has to be tuned for the microphone and the analog stage.
    float silentLimit = 0.0;

    /// Analog input pin of the channel.
    int pin = A0;

    /// Holds the average filter level. If the signal level rises above
    /// this level, a peak event will trigger.
    float avgSample = 0.0;

    /// The raw sample will be processed to this variable.
    float sample = 0;

    /// Previous value of the signal.
    float signalPrev = 0.0;

    /// Average peak signal.
    float avgPeak = 0.0;

    /// Offset of the ADC result.
    float offset = 512.0;

    /// Filter constant for average sample.
    float avgSampleFilterBeta = 0.3;

    /// Filter constant for sample.
    float sampleFilterBeta = 0.5;

    /// Function pointer to peak event function.
    void(*peakFunc)(void) = NULL;

};

/// Peak detector object.
extern musicChannel peak;

#endif