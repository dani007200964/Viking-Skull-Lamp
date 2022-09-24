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

unsigned long fogMachineTimer = 0;
unsigned long fogLastTurnOn = 0;
unsigned long fogCoolDownTimer = 0;
bool fogCoolDown = false;

void fogMachineInit(){

    pinMode( HUMIDIFIER_PIN, OUTPUT );
    digitalWrite( HUMIDIFIER_PIN, 0 );

}

void fogMachineUpdate(){

    unsigned long timerCalculated = (unsigned long)1000 * 60; // one minute

    if( ( ( (unsigned long)millis() - fogLastTurnOn ) > HUMIDIFIER_DURATION ) ){

        if( digitalRead( HUMIDIFIER_PIN ) ){

            digitalWrite( HUMIDIFIER_PIN, 0 );
            Serial.print( millis() );
            Serial.print( F( " : " ) );
            Serial.println( F( "Humidifier finished! Cool-down timer start..." ) );
            fogCoolDown = true;
            fogCoolDownTimer = millis();

        }

    }

    if( fogCoolDown && ( ( (unsigned long)millis() - fogCoolDownTimer ) > HUMIDIFIER_COOL_DOWN ) ){

        Serial.print( millis() );
        Serial.print( F( " : " ) );
        Serial.println( F( "Cooling finished!" ) );
        fogCoolDown = false;

    }

    switch( fogTimer ){

        case 0:
            timerCalculated = (unsigned long)15 * timerCalculated;
            //timerCalculated = (unsigned long)1 * timerCalculated; // DEBUG
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

    if( ( (unsigned long)millis() - fogMachineTimer ) > timerCalculated ){

        fogMachineTimer = millis();
        fogMachineEnable();
        Serial.print( millis() );
        Serial.print( F( " : " ) );
        Serial.println( F( "Timer elapsed, humidifier turning on..." ) );

    }

}

void fogMachineEnable(){

    if( !fogMachineEnabled ){

        return;

    }

    if( !digitalRead( HUMIDIFIER_PIN ) && !fogCoolDown ){

        fogLastTurnOn = millis();
        digitalWrite( HUMIDIFIER_PIN, 1 );

    }

}