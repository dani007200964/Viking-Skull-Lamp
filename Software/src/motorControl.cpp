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

#include "motorControl.hpp"

// Set the front state to unknown by default.
enum frontState_t frontState = FRONT_UNKNOWN;

void motorInit(){

    // Set the endstop pins to input.
    pinMode( FRONT_ENDSTOP, INPUT );
    pinMode( BACK_ENDSTOP, INPUT );

    // Set the motor pin to output.
    pinMode( MOTOR, OUTPUT );

    // Disable the motor.
    digitalWrite( MOTOR, 0 );

    // Check if the front state can be detected at startup.
    if( digitalRead( FRONT_ENDSTOP ) == 0 ){

        frontState = FRONT_OPEN;
        display.displayOn();
        Serial.println( F( "Front opened at startup!" ) );

    }

    else if( digitalRead( BACK_ENDSTOP ) == 0 ){

        frontState = FRONT_CLOSE;
        display.displayOff();
        Serial.println( F( "Front closed at startup!" ) );

    }

    else{

        closeFront();
        Serial.println( F( "Front state unknown! Closing..." ) );

    }

}

void openFront(){

    // Store the system time, when the procedure started.
    long timerStart;

    // Turn on the motor with the MOTOR_PWM power.
    analogWrite( MOTOR, MOTOR_PWM );

    // Save system time.
    timerStart = millis();

    // The endstps has inverted logic. If the
    // endstop is pressed, the output of it
    // will be low. Wait until the front endstop
    // is high.
    while( digitalRead( FRONT_ENDSTOP ) == 1 ){
        
        // Check for timeout.
        if( ( millis() - timerStart ) > OPEN_TIMEOUT ){

            // If timeout occured, stop the motor and return.
            digitalWrite( MOTOR, 0 );

            // Also set state to unknown.
            frontState = FRONT_UNKNOWN;
            display.displayOn();
            return;

        }

    }

    // If the endstop has triggered, we have to stop the motor.
    digitalWrite( MOTOR, 0 );

    // Turn on the display.
    display.displayOn();

    // Save the state.
    frontState = FRONT_OPEN;

}

void closeFront(){

    // Store the system time, when the procedure started.
    long timerStart;

    // Turn on the motor with the MOTOR_PWM power.
    analogWrite( MOTOR, MOTOR_PWM );

    // Save system time.
    timerStart = millis();

    // The endstps has inverted logic. If the
    // endstop is pressed, the output of it
    // will be low. Wait until the back endstop
    // is high.
    while( digitalRead( BACK_ENDSTOP ) == 1 ){
        
        // Check for timeout.
        if( ( millis() - timerStart ) > CLOSE_TIMEOUT ){

            // If timeout occured, stop the motor and return.
            digitalWrite( MOTOR, 0 );

            // Also set state to unknown.
            frontState = FRONT_UNKNOWN;
            display.displayOn();
            return;

        }

    }

    // If the endstop has triggered, we have to stop the motor.
    digitalWrite( MOTOR, 0 );

    // Save the state.
    frontState = FRONT_CLOSE;

    // Turn off the display.
    display.displayOff();

}