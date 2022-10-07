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

#include "musicVisualizer.hpp"

musicChannel::musicChannel( int pin_p, float silentLimit_p ){

  // Store arguments to internal variables.
  pin = pin_p;
  silentLimit = silentLimit_p;

}

musicChannel::musicChannel( int pin_p, float silentLimit_p, float offset_p  ){

  // Store arguments to internal variables.
  pin = pin_p;
  silentLimit = silentLimit_p;
  offset = offset_p;

}

musicChannel::musicChannel( int pin_p, float silentLimit_p, float offset_p, float avgSampleFilterBeta_p, float sampleFilterBeta_p ){

  // Store arguments to internal variables.
  pin = pin_p;
  silentLimit = silentLimit_p;
  offset = offset_p;
  avgSampleFilterBeta = avgSampleFilterBeta_p;
  sampleFilterBeta = sampleFilterBeta_p;

}

void musicChannel::attachPeakFunction( void(*peakFunc_p)(void) ){

  // Store function pointer to internal variable.
  peakFunc = peakFunc_p;
  
}

void musicChannel::update(){

  // Offset the raw signal to make it act like in the real world.
  sample = (float)analogRead( pin ) - offset;

  // If the signal has negative component flip it to the positive range.
  sample = abs( sample );

  // Generate the average sample with a complementary filter.
  avgSample = ( ( (float)sample ) * avgSampleFilterBeta + avgSample * ( 1.0 - avgSampleFilterBeta ) );

  // In cases when the signal is too low, make it 0 to no trigger any event.
  if( ( sample < ( avgSample / 2 ) ) || ( sample < silentLimit ) ){

    signal = 0;
    
  }

  // If the signal is strong enough, filter it with a complementary filter.
  else{

    signal = sample * sampleFilterBeta + signal * ( 1.0 - sampleFilterBeta );
    
  }

  // Always reduce the value of the signalMax variable. It is necessary for
  // noise floor level compensation. I think -10.0 per iteration is suitable.
  signalMax -= 10.0;

  // Limit it to 0.
  if( signalMax < 0.0 ){

    signalMax = 0.0;
    
  }

  // If the signal is above the stored max level,
  // save the max level.
  if( signalMax < signal ){

    signalMax = signal;
    
  }

  // If the signal changes rapidly we have to recalculate the average peak.
  if( ( ( signal - signalPrev ) > ( avgSample - signalPrev ) ) && ( ( avgSample - signalPrev ) > 0 ) ){

    avgPeak = ( avgPeak + ( signal - signalPrev ) ) / 2.0;
    
  }

  // If the signal change is greater than the average peak, it means we have a peak event.
  peak = ( signal - signalPrev ) > avgPeak;

  // If peak event occured, and peakFunction is attached, call that function.
  if( peak && ( peakFunc != NULL ) ){

    peakFunc();
    
  }

  // Change the signal to the signalPrev variable.
  signalPrev = signal;
      
}

musicChannel peak( SOUND_PEAK, 20.0, 0.0, 0.5, 0.5 );
