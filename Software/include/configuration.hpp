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

#ifndef CONFIGURATION_HPP__
#define CONFIGURATION_HPP__

#include "Arduino.h"
#include "EEPROM.h"

#define createData( x ) { .dataPointer = &x, .dataSize = sizeof( x ) }

class configurationManager{

public:

    typedef struct{

        void* dataPointer;
        uint8_t dataSize;

    }configurationData_t;

    configurationManager( configurationData_t *configTree_p, uint8_t configTreeSize_p );

    void saveConfig();
    bool loadConfig();

private:

    /// Maxim like crc-8
    void crcFeed( uint8_t data );
    
    configurationData_t *configTree = NULL;
    uint8_t configTreeSize = 0;

    uint8_t crc = 0xff;

};

#endif