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

#include "configuration.hpp"

configurationManager::configurationManager( configurationData_t *configTree_p, uint8_t configTreeSize_p ){

    // Save the pointer and the size to internal variable.
    configTree = configTree_p;
    configTreeSize = configTreeSize_p;

}

void configurationManager::saveConfig(){

    // Generic counter variables.
    uint8_t i;
    uint8_t j;

    // Index of the next byte that should be written.
    // It also shows how many bytes have been written.
    uint16_t index = 0;

    // Points to the next byte that should be written.
    uint8_t *dataPtr;

    // Reset CRC to default.
    crc = 0x00;

    Serial.println( F( "Saving bytes:" ) );
    for( i = 0; i < configTreeSize; i++ ){

        dataPtr = (uint8_t*)configTree[ i ].dataPointer;

        for( j = 0; j < configTree[ i ].dataSize; j++ ){

            Serial.print( F( "\tElement: " ) );
            Serial.print( i );
            Serial.print( F( "\t" ) );
            Serial.print( index );
            Serial.print( F( "\t: " ) );
            Serial.print( *dataPtr );
            Serial.print( F( "\tHEX: " ) );
            Serial.println( *dataPtr, HEX );

            EEPROM.update( index, *dataPtr );
            crcFeed( *dataPtr );

            dataPtr++;
            index++;

        }

    }

    // Write the CRC as well.
    EEPROM.update( index, crc );

    Serial.print( F( "\tCalculated CRC: " ) );
    Serial.println( crc );

}

bool configurationManager::loadConfig(){

    // Generic counter variables.
    uint8_t i;
    uint8_t j;

    // Index of the next byte that should be read.
    // It also shows how many bytes have been read.
    uint16_t index = 0;

    // Points to the next byte that should be read.
    uint8_t *dataPtr;

    // We will read the stored CRC from the EEPROM to this variable.
    uint8_t crcRead = 0;

    // Reset CRC to default.
    crc = 0x00;

    Serial.println( F( "Loading bytes:" ) );
    for( i = 0; i < configTreeSize; i++ ){

        dataPtr = (uint8_t*)configTree[ i ].dataPointer;

        for( j = 0; j < configTree[ i ].dataSize; j++ ){

            *dataPtr = EEPROM.read( index );

            Serial.print( F( "\tElement: " ) );
            Serial.print( i );
            Serial.print( F( "\t" ) );
            Serial.print( index );
            Serial.print( F( "\t: " ) );
            Serial.print( *dataPtr );
            Serial.print( F( "\tHEX: " ) );
            Serial.println( *dataPtr, HEX );

            crcFeed( *dataPtr );

            dataPtr++;
            index++;

        }

    }

    // Read the stored CRC.
    crcRead = EEPROM.read( index );

    // Compare the two CRC
    if( crcRead != crc ){

        Serial.print( F( "\tCRC error! Calculated: " ) );
        Serial.print( crc );
        Serial.print( F( ", read: " ) );
        Serial.println( crcRead );
        return false;

    }

    Serial.print( F( "\tCRC OK! Calculated: " ) );
    Serial.print( crc );
    Serial.print( F( ", read: " ) );
    Serial.println( crcRead );

    return true;

}

void configurationManager::crcFeed( uint8_t data ){

    uint8_t j;

    crc ^= data;

    for( j = 0; j < 8; j++ ){

        if( ( crc & 0x80 ) != 0 ){

            crc = (uint8_t)( ( crc << 1 ) ^ 0x31 );

        }

        else{

            crc <<= 1;

        }

    }

}