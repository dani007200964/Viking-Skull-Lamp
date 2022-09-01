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

#include "musicVisualizer.hpp"

musicChannel::musicChannel( int pin_p, float silentLimit_p ){

  pin = pin_p;
  silentLimit = silentLimit_p;

}

musicChannel::musicChannel( int pin_p, float silentLimit_p, float offset_p  ){

  pin = pin_p;
  silentLimit = silentLimit_p;
  offset = offset_p;

}

musicChannel::musicChannel( int pin_p, float silentLimit_p, float offset_p, float avgSampleFilterBeta_p, float ampleFilterBeta_p ){

  pin = pin_p;
  silentLimit = silentLimit_p;
  offset = offset_p;
  avgSampleFilterBeta = avgSampleFilterBeta_p;
  ampleFilterBeta = ampleFilterBeta_p;

}

void musicChannel::attachPeakFunction( void(*peakFunc_p)(void) ){

  peakFunc = peakFunc_p;
  
}

void musicChannel::update(){

  sample = (float)analogRead( pin ) - offset;

  sample = abs( sample );

  avgSample = ( ( (float)sample ) * avgSampleFilterBeta + avgSample * ( 1.0 - avgSampleFilterBeta ) );

  if( ( sample < ( avgSample / 2 ) ) || ( sample < silentLimit ) ){

    signal = 0;
    
  }

  else{

    signal = sample * ampleFilterBeta + signal * ( 1.0 - ampleFilterBeta );
    
  }

  signalMax -= 10.0;

  if( signalMax < 0.0 ){

    signalMax = 0.0;
    
  }

  if( signalMax < signal ){

    signalMax = signal;
    
  }

  if( ( ( signal - signalPrev ) > ( avgSample - signalPrev ) ) && ( ( avgSample - signalPrev ) > 0 ) ){

    avgPeak = ( avgPeak + ( signal - signalPrev ) ) / 2.0;
    
  }


  peak = ( signal - signalPrev ) > avgPeak;

  if( peak && ( peakFunc != NULL ) ){

    peakFunc();
    
  }

  signalPrev = signal;
      
}

musicChannel peak( SOUND_PEAK, 20.0, 0.0, 0.5, 0.5 );
