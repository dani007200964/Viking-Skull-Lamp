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

#ifndef CONFIGURATION_HPP__
#define CONFIGURATION_HPP__

#include "Arduino.h"
#include "EEPROM.h"

#define createData( x ) { .dataPointer = &x, .dataSize = sizeof( x ) }

/// Configuration Manager Class
///
/// This class handles the saving and loading any type of data.
/// The data has to be specified in an array called configTree.
/// You can use the @ref createData macro to simplify the configTree
/// creation.
/// @see createData
class configurationManager{

public:

    /// Type for configTree element.
    ///
    /// You don't have to fill it manually, the @ref createData
    /// macro does this for you.
    typedef struct{

        void* dataPointer; ///< Pointer for the data, that has to be stored or loaded. The type is void* to support any kind of data.
        uint8_t dataSize;  ///< The size of the data, that has to be stored or loaded. Specified in bytes.

    }configurationData_t;

    /// Constructor
    /// @param configTree_p Pointer to the configTree.
    /// @param configTreeSize_p Size of the configTree.
    configurationManager( configurationData_t *configTree_p, uint8_t configTreeSize_p );

    /// Save configuration to EEPROM.
    ///
    /// You shall call this when you have changed some
    /// of the elements value in the configTree. The function
    /// generates a CRC and store it as well, to detect data
    /// corruption.
    /// @note You can call this every time when some key parameter changes. It will only write the EEPROM if something actually changed.
    void saveConfig();

    /// Load configuration from EEPROM.
    ///
    /// Typically you should call this at startup.
    /// It loads the previously saved configuration
    /// from the EEPROM to the elements in the
    /// configTree. The function calculates a CRC
    /// from the stored data and compare it with a
    /// stored CRC. If they doesn't match, that means
    /// the saved data has corrupted( or the EEPROM was empty ).
    /// In this case it wont update the elements in the
    /// configTree with the wrong values.
    bool loadConfig();

private:

    /// Maxim like crc-8
    void crcFeed( uint8_t data );
    
    /// Pointer to configTree.
    configurationData_t *configTree = NULL;

    /// configTree size.
    uint8_t configTreeSize = 0;

    /// Calculated CRC.
    uint8_t crc = 0xff;

};

#endif