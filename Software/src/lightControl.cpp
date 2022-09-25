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

#include "lightControl.hpp"

/// Pixel buffer for the LED strip.
CRGB stripLightBuffer[ LIGHT_STRIP_SIZE ];

/// Pixel buffer for the LED disc.
CRGB skullLightBuffer[ LIGHT_SKULL_SIZE ];

/// Stores the last system time when the last light update event happened.
unsigned long lightTimer = 0;

/// Stores the last system time when the last sample update event happened.
unsigned long sampleTimer = 0;

/// Stores the direction and speed of the fading.
int fadeDirection = 0;

/// The actual brightness of the strips are calculated
/// to this variable. It is required because of the fading
/// effets.
int fadedBrightness = 0;

/// This is a flag, that shows the actual state of the lighting.
bool lightStateOn = false;

/// Flag for peak detection. It is used for the clap detection
bool prevPeak = false;

/// Flag for beat detection. It is used for the music visualizer.
bool prevBeat = false;

/// This array is used for the clap detection. It is a circular
/// buffer, that stores the previous four system time, when a
/// peak is detected. The element 3 is the latest peak time,
/// the element 0 is the oldest.
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

    // Check if we have to update the lighting.
    if( ( (unsigned long)millis() - lightTimer ) > LIGHT_UPDATE_RATE ){

        // Handle the fading effect.
        fadedBrightness += fadeDirection;

        // Handle the limits if the fadedBrightness variable
        if( fadeDirection > 0 ){

            // Check if saturated.
            if( fadedBrightness >= lightBrightness ){

                // If it reached the upper limit stop the fading.
                fadedBrightness = lightBrightness;
                fadeDirection = 0;

            }

        }

        // Handle the limits if the fadedBrightness variable
        else if( fadeDirection < 0 ){

            // Check if saturated.
            if( fadedBrightness <= 0 ){

                // If it reached the lower limit stop the fading.
                fadedBrightness = 0;
                fadeDirection = 0;

            }

        }

        // Every other case( basically that means fading is stopped ),
        // when the lighting is on, we set the fadedBrightness to the
        // lightBrightness, which is configured in the menu.
        else if( lightStateOn ){

            fadedBrightness = lightBrightness;

        }

        // Set the calculated brightness.
        FastLED.setBrightness( fadedBrightness );

        // We have to select the right update function
        // depending on the lightMode, which is configured
        // in the menu.
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
        
        // Send the calculated data from the pixel buffers to the LEDs.   
        FastLED.show();

        // Store the system time for the next update timing.
        lightTimer = millis();

    }

    // Check if we have to update the clap detector.
    if( ( (unsigned long)millis() - sampleTimer ) > SAMPLE_UPDATE_RATE ){

        // Update the peak detector.
        peak.update();

        // Check if we have a peak.
        if( peak.peak == true && prevPeak == false ){

            // Shift down the elements in the curcular buffer.
            peakTimes[ 0 ] = peakTimes[ 1 ];
            peakTimes[ 1 ] = peakTimes[ 2 ];
            peakTimes[ 2 ] = peakTimes[ 3 ];
            peakTimes[ 3 ] = millis();            

            // Calculate the time between the two oldest peaks.
            unsigned long delta = peakTimes[ 1 ] - peakTimes[ 0 ];

            // At least 1000ms has to elapse after the prevoius clap.
            if( delta > 1000 ){

                // Try to detect the pattern from the time between the claps.
                delta = peakTimes[ 2 ] - peakTimes[ 1 ];
                if( ( delta > 400 ) && ( delta < 900 ) ){

                    delta = peakTimes[ 3 ] - peakTimes[ 2 ];
                    if( ( delta > 50 ) && ( delta < 450 ) ){

                        Serial.println( F( "Clap pattern match!" ) );

                        // The following has to acomplish to toggle the lights:
                        // * Clap switch function has to be enabled.
                        // * We are not in music mode. The clap detector become mad when the drop kicks in.
                        // * Front has to be closed.
                        if( clapSwitchEnabled && ( lightMode != LIGHT_MODE_MUSIC ) && ( frontState == FRONT_CLOSE ) ){

                            // Play the melody and toggle the lights.
                            clapMelody();
                            lightToggle();

                        }

                    }

                }

            }

        }

        // Store the current peak state.
        prevPeak = peak.peak;

        // Store the system time for the next update timing.
        sampleTimer = millis();

    }



}

void lightModeRainbowUpdate(){

    // Generic counter.
    uint8_t i;

    // Hue value will be calculated here.
    uint8_t hue;

    // Fold a rainbow pattern around the LED strip,
    // and make it slowly rotate.
    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        // Calculate the rainbow color according to the
        // position on the LED strep.
        hue = (uint8_t)( (uint16_t)i * 255 / LIGHT_STRIP_SIZE );

        // Shift it a slowly by a timer and limit it between 0 - 255.
        hue = (uint8_t)( (unsigned long)( hue + millis() / 100 ) % 255 );

        // Store the pixel value.
        stripLightBuffer[ i ].setHSV( hue, 255, 255 );

    }

    // The LED disc will lit as one color. This color also changy by time.
    hue = (uint8_t)( (unsigned long)( millis() / 100 ) % 255 );

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( hue, 255, 255 );

    }

}

void lightModeCandleUpdate(){

    // Generic counter.
    uint8_t i;

    // Value will be calculated here for each pixel on the LED strip.
    float value;

    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        // Now this is something. It basically wraps a sine wawe around the LED strip.
        // * When the result of the sine function is -1.0, the brigntess will be 0 ( off ).
        // * When the result of the sine function is 1.0, the brigntess will be 255 ( full brightness ).
        // Also it is rotated by time.
        //   sine function     ms      rotation              map it for the    it tells how many sine   convert from    convert from
        //                    timer     speed                LED strip size    periods will be mapped    -1.0 - 1.0       0.0 - 1.0
        //                                                                                              to 0.0 - 1.0     to 0 - 255
        //         |            |          |                         |                          |           |           |
        //         ˇ            ˇ          ˇ                         ˇ                          ˇ           ˇ           ˇ
        value = ( sin( (float)millis() / 500.0 + (float)i / (float)LIGHT_STRIP_SIZE * TWO_PI * 2.0  ) / 2.0 + 0.5 ) * 255;

        // Set the valie for each pixel with a mystic blue color.
        stripLightBuffer[ i ].setHSV( 136, 163, (uint8_t)value );

    }

    // For the led disc we want to imitate that a candle is placed inside the skull.
    // We split the LED disc to two color components a warmer orange-ish color and
    // a colder yellow-ish one. The intensity if these pixels will be random. to
    // mimic a flame in a candle. I think it is realistic enoug, but if you doesn't
    // like it, you can tweak the parameters.
    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        // Select the even indexed pixels.
        if( i % 2 == 0 ){

            skullLightBuffer[ i ].setHSV( 31, 138, random( 50 ) + 205 );

        }

        // Select the odd indexed pixels.
        else{

            skullLightBuffer[ i ].setHSV( 20, 237, random( 50 ) + 305 );

        }

    }

}

void lightModePulseUpdate(){

    // Generic counter.
    uint8_t i;

    // The value parameter will change according a sine wave.
    // The sine function is modulated by the millis() timer.
    float value;

    // The hue component will be stored to this variable.
    // It is static to not lose value between function calls.
    static uint8_t hue;

    // Flag that shows, that random generation required.
    // It is static to not lose value between function calls.
    static bool generate = true;

    // Calculate the value.
    value = ( sin( (float)millis() / 1500.0 ) );

    // If the value is less than zero it's time
    // to generate a new hue component.
    if( value < 0.0 ){

        // Also a the new hue should be generated az tero cross event
        // when the return value of the sine function goes positive
        // to negative. The generate flag is responsible to detect
        // the zero crossing event.
        if( generate ){

            // Generate a new hue value between 0 and 255.
            hue = random( 0, 255 );

            // Clear the generate flag to skip value generation
            // for the rest of the negative period.
            generate = false;

        }

    }

    // If the value is greater or equal to zero we have to display
    // the generated hue with the value.
    else{

        // This if statement detect the positive zero crossing event.
        if( !generate ){

            // In this case we set the generate flag. It is required to
            // detect the next negative zero crossing.
            generate = true;

        }

        // The sine function generates an output between -1.0 and 1.0.
        // We skip for the negative part, but we have to mupltiply the
        // positive part by 255 to make it's range between 0 and 255.0.
        value *= 255;

        // Set all LEDs in the strip with this value.
        for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

            stripLightBuffer[ i ].setHSV( hue, 255, (uint8_t)value );

        }

        // This multiplication creates a simple effect.
        // The LEDs on the LED disc wil turn on faster,
        // than the LEDs on the strip.
        value *= 5;

        // Becouse the previous multiplication we have to limit the
        // value to 255.
        if( value > 255 ){

            value = 255;

        }

        // Set all LEDs in the strip with the value and hue + 128. Why?
        // The hue parameter represents all the visible colors between 0 and 255.
        // If we add 128 to it the resoulting color will be the complementary color
        // of the original one. The complementary color pairs ar always looks nice
        // next to each other.
        for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

            skullLightBuffer[ i ].setHSV( (uint8_t)( hue + 128 ), 255, (uint8_t)value );

        }

    }

}

void lightModeMusicUpdate(){

    // Generic counter variable.
    uint8_t i;

    // Hue parameter will be stored here.
    uint8_t hue;

    // Value parameter will be stored here.
    float value;

    // The hue value will be filtered with a complementary
    // filter, and the result will be stored here.
    // It is static to not lose value between function calls.
    static float hueFiltered = 0.0;

    // The speed variable is used to modulete the rotation
    // effect on the LED strip.
    // It is static to not lose value between function calls.
    static float speed = 0.0;

    // This variable counts the number of peaks in a period.
    // It is used to detect some crazy drops in the music.
    // It is static to not lose value between function calls.
    static uint16_t peakCounter = 0;

    // The default value of the LED disc in the skull is 128.
    static float skullValue = 128.0;

    // This variable stores the hue component of the LED disc.
    static uint8_t skullHue = 0;

    // The hue parameter is just changing by time. It goes from
    // 0 to 255 linearly and starts again.
    hue = (uint8_t)( (unsigned long)( millis() / 100 ) % 255 );

    // Apply 90% complementary filtering to hue.
    hueFiltered = 0.1 * (float)hue + 0.9 * hueFiltered;

    // Apply 90% complementary filtering to skullValue.
    skullValue = 0.1 * (float)50.0 + 0.9 * skullValue;

    // Detect if we have a peak.
    if( peak.peak == true && prevBeat == false ){

        // Instantly crank up the value of the LEDs in the skull
        // to make it reactive to the beat.
        skullValue = 200.0;

        // Add some value to the skullHue to generate a new color for
        // the beat.
        skullHue += 15;

        // Instantly generate the complementary color of the hue component.
        hueFiltered = (float)( (uint8_t)( ( (uint8_t)hue ) + 128 ) );

        // Add some value to the speed variable.
        // It will modulete the rotation later.
        speed += PI / 8.0;

        // Add some value to the peak counter.
        peakCounter += 10;

        // If the peakCounter exceeds 300, that means
        // we have some serious drop in the music.
        if( peakCounter > 300 ){

            // If the lights are turned on, we respond to the
            // drop with some smoke.
            if( lightStateOn ){

                fogMachineEnable();

            }

            // Also we have to reset the peak counter.
            peakCounter = 0;

        }


    }

    // Save the beat state.
    prevBeat = peak.peak;

    // Every iteration we have to decrement the peakCounter
    // if it's above 0. It will act like a digital UV meter.
    if( peakCounter > 0 ){

        peakCounter--;

    }

    // limit the speed variable to 2 pi.
    if( speed > TWO_PI ){

        speed = 0.0;

    }

    // Calculate the value parameter for each LED in the strip.
    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){


        // Now this is something. It basically wraps a sine wawe around the LED strip.
        // * When the result of the sine function is -1.0, the brigntess will be 0 ( off ).
        // * When the result of the sine function is 1.0, the brigntess will be 255 ( full brightness ).
        // Also it is rotated by time.
        //   sine function     ms      rotation              map it for the    it tells how many sine  modul.  convert from   convert from
        //                    timer     speed                LED strip size    periods will be mapped  fact.    -1.0 - 1.0     0.0 - 1.0
        //                                                                                                      to 0.0 - 1.0   to 0 - 255
        //         |            |          |                         |                          |        |          |           |
        //         ˇ            ˇ          ˇ                         ˇ                          ˇ        ˇ          ˇ           ˇ
        value = ( sin( (float)millis() / 2000.0 + (float)i / (float)LIGHT_STRIP_SIZE * TWO_PI * 2.0 + speed ) / 2.0 + 0.5 ) * 255;

        // Fill the pixel buffer with the calculated colors.
        stripLightBuffer[ i ].setHSV( (uint8_t)hueFiltered, 163, (uint8_t)value );

    }

    // Fill the pixel buffer with the calculated colors.
    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( skullHue, 128, (uint8_t)skullValue );

    }


}

void lightModeKomodoUpdate(){

    // Generic counter.
    uint8_t i;

    // We set a bright light.
    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        stripLightBuffer[ i ].setHSV( 43, 61, 255 );

    }

    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( 255, 0, 255 );

    }

}

void lightModeColorUpdate(){

    // Generic counter.
    uint8_t i;

    // In this mode we set the user defined value to the strip.
    for( i = 0; i < LIGHT_STRIP_SIZE; i++ ){

        stripLightBuffer[ i ].setHSV( selectedColor, 255, 255 );

    }

    // And create the complementary color for the skull.
    for( i = 0; i < LIGHT_SKULL_SIZE; i++ ){

        skullLightBuffer[ i ].setHSV( (uint8_t)( selectedColor + 128 ), 255, 255 );

    }

}

