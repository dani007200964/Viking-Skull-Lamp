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
Copyright (c) 2020 Daniel Hajnal
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

#include "buzzerControl.hpp"

void buttonClickSound(){

    if( buzzerEnabled ){

        tone( SPEAKER_PIN, BUTTON_CLICK_FREQUENCY, BUTTON_CLICK_DURATION );

    }

}

void encoderRotateSound(){

    if( buzzerEnabled ){

        tone( SPEAKER_PIN, ENCODER_ROTATE_FREQUENCY, ENCODER_ROTATE_DURATION );
    
    }

}

void playMelody( uint16_t data[][ 2 ], uint8_t dataSize ){

    uint8_t i;

    if( !buzzerEnabled ){

        return;

    }

    for( i = 0; i < dataSize; i++ ){

        tone( SPEAKER_PIN, data[ i ][ 0 ], data[ i ][ 1 ] );
        delay( data[ i ][ 1 ] );

    }

}

void openCloseMelody(){

    if( !buzzerEnabled ){

        return;

    }
    
    tone( SPEAKER_PIN, NOTE_F3, 100 );
    delay( 100 );

    tone( SPEAKER_PIN, NOTE_GS3, 100 );
    delay( 100 );

    tone( SPEAKER_PIN, NOTE_B3, 100 );
    delay( 100 );

    tone( SPEAKER_PIN, NOTE_C3, 300 );
    delay( 300 );

}

void clapMelody(){

    if( !buzzerEnabled ){

        return;

    }
    
    tone( SPEAKER_PIN, NOTE_C2, 50 );
    delay( 50 );

    tone( SPEAKER_PIN, NOTE_C3, 50 );
    delay( 50 );

    tone( SPEAKER_PIN, NOTE_C4, 50 );
    delay( 50 );

    tone( SPEAKER_PIN, NOTE_C5, 100 );
    delay( 100 );

}

void turnOnMelody(){

    if( buzzerEnabled ){

        tone( SPEAKER_PIN, TURN_ON_SOUND_FREQUENCY, TURN_ON_SOUND_DURATION );

    }

}