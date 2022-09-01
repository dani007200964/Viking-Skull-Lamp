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

#include "lightControl.hpp"

CRGB stripLightBuffer[ LIGHT_STRIP_SIZE ];
CRGB skullLightBuffer[ LIGHT_SKULL_SIZE ];

unsigned long lightTimer = 0;
unsigned long sampleTimer = 0;

int fadeDirection = 0;
int fadedBrightness = 0;

bool lightStateOn = false;

bool prevPeak = false;

bool prevBeat = false;

unsigned long peakTimes[ 4 ] = { 0 };

void lightInit(){

    FastLED.addLeds<NEOPIXEL, LIGHT_STRIP_PIN>( stripLightBuffer, LIGHT_STRIP_SIZE );
    FastLED.addLeds<NEOPIXEL, LIGHT_SKULL_PIN>( skullLightBuffer, LIGHT_SKULL_SIZE );

    FastLED.setBrightness( lightBrightness );

    FastLED.clear();
    FastLED.show();

}

void lightOn(){

    fadeDirection = LIGHT_FADE_RATE;
    lightStateOn = true;

}
void lightOff(){

    fadeDirection = -LIGHT_FADE_RATE;
    lightStateOn = false;

}

void lightToggle(){

    if( lightStateOn ){
    
        lightOff();
    
    }

    else{

        lightOn();

    }

}

void lightUpdate(){

    if( ( (unsigned long)millis() - lightTimer ) > LIGHT_UPDATE_RATE ){

        fadedBrightness += fadeDirection;

        if( fadeDirection > 0 ){

            if( fadedBrightness >= lightBrightness ){

                fadedBrightness = lightBrightness;
                fadeDirection = 0;

            }

        }

        else if( fadeDirection < 0 ){

            if( fadedBrightness <= 0 ){

                fadedBrightness = 0;
                fadeDirection = 0;

            }

        }

        else if( lightStateOn ){

            fadedBrightness = lightBrightness;

        }


        FastLED.setBrightness( fadedBrightness );

        switch( lightMode ){

            case LIGHT_MODE_RAINBOW:

                lightModeRainbowUpdate();
            
            break;

            case LIGHT_MODE_CANDLE:

                lightModeCandleUpdate();

            break;

            case LIGHT_MODE_PULSE:

                lightModePulseUpdate();

            break;

            case LIGHT_MODE_MUSIC:

                lightModeMusicUpdate();

            break;

            case LIGHT_MODE_KOMODO:

                lightModeKomodoUpdate();

            break;

            case LIGHT_MODE_COLOR:

                lightModeColorUpdate();

            break;

        }
        
        // skullLightBuffer[ 0 ].setHSV( selectedColor, 255, 255 );
        
        FastLED.show();

        lightTimer = millis();

    }

    if( ( (unsigned long)millis() - sampleTimer ) > SAMPLE_UPDATE_RATE ){

        peak.update();

        if( peak.peak == true && prevPeak == false ){

            peakTimes[ 0 ] = peakTimes[ 1 ];
            peakTimes[ 1 ] = peakTimes[ 2 ];
            peakTimes[ 2 ] = peakTimes[ 3 ];
            peakTimes[ 3 ] = millis();

            /*
            Serial.print( F( "Peak times: " ) );
            Serial.print( peakTimes[ 0 ] );
            Serial.print( F( ", " ) );
            Serial.print( peakTimes[ 1 ] );
            Serial.print( F( ", " ) );
            Serial.print( peakTimes[ 2 ] );
            Serial.print( F( ", " ) );
            Serial.print( peakTimes[ 3 ] );
            Serial.println( F( ", " ) );
            */
            

            unsigned long delta = peakTimes[ 1 ] - peakTimes[ 0 ];
            if( delta > 1000 ){

                delta = peakTimes[ 2 ] - peakTimes[ 1 ];
                if( ( delta > 400 ) && ( delta < 900 ) ){

                    delta = peakTimes[ 3 ] - peakTimes[ 2 ];
                    if( ( delta > 50 ) && ( delta < 450 ) ){

                        Serial.println( F( "Clap pattern match!" ) );

                        if( clapSwitchEnabled && ( lightMode != LIGHT_MODE_MUSIC ) && ( frontState == FRONT_CLOSE ) ){

                            clapMelody();
                            lightToggle();

                        }

                    }

                }

            }

        }

        prevPeak = peak.peak;

        sampleTimer = millis();

    }



}

void lightModeRainbowUpdate(){

    uint8_t i;
    uint8_t hue;

    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        hue = (uint8_t)( (uint16_t)i * 255 / LIGHT_STRIP_SIZE );

        hue = (uint8_t)( (unsigned long)( hue + millis() / 100 ) % 255 );

        stripLightBuffer[ i ].setHSV( hue, 255, 255 );

    }

    hue = (uint8_t)( (unsigned long)( millis() / 100 ) % 255 );

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( hue, 255, 255 );

    }

}

void lightModeCandleUpdate(){

    uint8_t i;
    float value;

    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        value = ( sin( (float)millis() / 500.0 + (float)i / (float)LIGHT_STRIP_SIZE * TWO_PI * 2.0  ) / 2.0 + 0.5 ) * 255;
        stripLightBuffer[ i ].setHSV( 136, 163, (uint8_t)value );

    }

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        if( i % 2 == 0 ){

            skullLightBuffer[ i ].setHSV( 31, 138, random( 50 ) + 205 );

        }

        else{

            skullLightBuffer[ i ].setHSV( 20, 237, random( 50 ) + 305 );

        }

    }

}

void lightModePulseUpdate(){

    uint8_t i;
    float value;
    static uint8_t hue;
    static bool generate = true;

    value = ( sin( (float)millis() / 1500.0 ) );

    if( value < 0.0 ){

        if( generate ){

            hue = random( 0, 255 );
            generate = false;

        }

    }

    else{

        if( !generate ){

            generate = true;

        }

        value *= 255;

        for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

            stripLightBuffer[ i ].setHSV( hue, 255, (uint8_t)value );

        }

        value *= 5;

        if( value > 255 ){

            value = 255;

        }

        for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

            skullLightBuffer[ i ].setHSV( (uint8_t)( hue + 128 ), 255, (uint8_t)value );

        }

    }

}

void lightModeMusicUpdate(){

    uint8_t i;
    uint8_t hue;
    float value;
    static float hueFiltered = 0.0;
    static float speed = 0.0;
    static uint16_t peakCounter = 0;

    static float skullValue = 128.0;
    static uint8_t skullHue = 0;

    hue = (uint8_t)( (unsigned long)( millis() / 100 ) % 255 );
    hueFiltered = 0.1 * (float)hue + 0.9 * hueFiltered;
    skullValue = 0.1 * (float)50.0 + 0.9 * skullValue;

    if( peak.peak == true && prevBeat == false ){

        skullValue = 200.0;
        skullHue += 15;
        hueFiltered = (float)( (uint8_t)( ( (uint8_t)hue ) + 128 ) );
        speed += PI / 8.0;
        peakCounter += 10;

        if( peakCounter > 300 ){

            if( lightStateOn ){

                fogMachineEnable();

            }
            peakCounter = 0;

        }


    }

    prevBeat = peak.peak;

    if( peakCounter > 0 ){

        peakCounter--;

    }

    if( speed > TWO_PI ){

        speed = 0.0;

    }

    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        value = ( sin( (float)millis() / 2000.0 + (float)i / (float)LIGHT_STRIP_SIZE * TWO_PI * 2.0 + speed ) / 2.0 + 0.5 ) * 255;
        stripLightBuffer[ i ].setHSV( (uint8_t)hueFiltered, 163, (uint8_t)value );

    }

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( skullHue, 128, (uint8_t)skullValue );

    }


}

void lightModeKomodoUpdate(){

    uint8_t i;

    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        stripLightBuffer[ i ].setHSV( 43, 61, 255 );

    }

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( 255, 0, 255 );

    }

}

void lightModeColorUpdate(){

    uint8_t i;

    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        stripLightBuffer[ i ].setHSV( selectedColor, 255, 255 );

    }

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( (uint8_t)( selectedColor + 128 ), 255, 255 );

    }

}

