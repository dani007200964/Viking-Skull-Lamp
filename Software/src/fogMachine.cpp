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

#include "fogMachine.hpp"

/// This variable is used for automatic humidification.
/// It stores the last system time when the humidifier
/// was turned on by the automated logic.
unsigned long fogMachineTimer = 0;

/// This variable stores the last system time when the
/// humidifier was turned on by any reason.
unsigned long fogLastTurnOn = 0;

/// This variable stores the last system time when the
/// cool down event happened. From this time whe should
/// not turn on the humidifier for @ref HUMIDIFIER_COOL_DOWN
/// duration.
unsigned long fogCoolDownTimer = 0;

/// If the cool down procedure still in progress, this flag will be true.
bool fogCoolDown = false;

void fogMachineInit(){

    pinMode( HUMIDIFIER_PIN, OUTPUT );
    digitalWrite( HUMIDIFIER_PIN, 0 );

}

void fogMachineUpdate(){

    // Calculate one minute in ms.
    unsigned long timerCalculated = (unsigned long)1000 * 60; // one minute

    // Check if the maximum allowed on time has expired.
    if( ( ( (unsigned long)millis() - fogLastTurnOn ) > HUMIDIFIER_DURATION ) ){

        // If the humidifier is turned of we have to turn if off.
        if( digitalRead( HUMIDIFIER_PIN ) ){

            digitalWrite( HUMIDIFIER_PIN, 0 );
            Serial.print( millis() );
            Serial.print( F( " : " ) );
            Serial.println( F( "Humidifier finished! Cool-down timer start..." ) );

            // Start the cool down procedure by setting
            // the flag and saving the system time.
            fogCoolDown = true;
            fogCoolDownTimer = millis();

        }

    }

    // Check if the cool down period expired.
    if( fogCoolDown && ( ( (unsigned long)millis() - fogCoolDownTimer ) > HUMIDIFIER_COOL_DOWN ) ){

        Serial.print( millis() );
        Serial.print( F( " : " ) );
        Serial.println( F( "Cooling finished!" ) );

        // If the cool down procedure finished,
        // clear the flag.
        fogCoolDown = false;

    }

    // In this section we just calculate the automatic humidification
    // periods based on the fogTimer variable.
    switch( fogTimer ){

        case 0:
            timerCalculated = (unsigned long)15 * timerCalculated;
        break;

        case 1:
            timerCalculated = (unsigned long)30 * timerCalculated;
        break;

        case 2:
            timerCalculated = (unsigned long)45 * timerCalculated;
        break;

        case 3:
            timerCalculated = (unsigned long)60 * timerCalculated;
        break;

        case 4:
            timerCalculated = (unsigned long)90 * timerCalculated;
        break;

        case 5:
            timerCalculated = (unsigned long)120 * timerCalculated;
        break;

        case 6:
            timerCalculated = (unsigned long)180 * timerCalculated;
        break;

        case 7:
            timerCalculated = (unsigned long)300 * timerCalculated;
        break;

        case 8:
            timerCalculated = (unsigned long)480 * timerCalculated;
        break;

        case 9:
            timerCalculated = (unsigned long)720 * timerCalculated;
        break;

        case 10:
            timerCalculated = (unsigned long)1440 * timerCalculated;
        break;

        default:

            return;

        break;

    }

    // Check if the automatic humidification has to be turned on.
    if( ( (unsigned long)millis() - fogMachineTimer ) > timerCalculated ){

        // Save the system time for the logic.
        fogMachineTimer = millis();
        
        // Try to enable the humidifier.
        fogMachineEnable();
        Serial.print( millis() );
        Serial.print( F( " : " ) );
        Serial.println( F( "Timer elapsed, humidifier turning on..." ) );

    }

}

void fogMachineEnable(){

    // If the humidifier is disabled we are not allowed to turn it on.
    if( !fogMachineEnabled ){

        return;

    }

    // If the humidifier pin is off and the cool down procedure
    // expired, we are allowed to turn on the humidifier.
    if( !digitalRead( HUMIDIFIER_PIN ) && !fogCoolDown ){

        // Save the system time for the logic.
        fogLastTurnOn = millis();
        digitalWrite( HUMIDIFIER_PIN, 1 );

    }

}