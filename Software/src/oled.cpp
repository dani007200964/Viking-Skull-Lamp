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

#include "oled.hpp"

ssd1306::ssd1306( uint8_t address_p ){

    address = address_p;
  
}

bool ssd1306::begin(){

    // Initialize I2C peripheral.
    Wire.begin();

    // Set the clock speed to 400kHz of the I2C bus.
    Wire.setClock( 400000 );

    // Check for the presence of the display on the bus.
    // If it fails, you may check the address.
    Wire.beginTransmission( address );
    if( Wire.endTransmission() != 0 ){

        return false;
        
    }

    // Set Memory Addressing Mode
    writeCommand( 0x20 );
    // Horizontal Addressing Mode
    writeCommand( 0x00 );

    // Set Page Start Address
    writeCommand( 0xB0 );
    // Set COM Output Direction
    writeCommand( 0xC8 );

    // Set Low Collumn Address
    writeCommand( 0x00 );
    // Set High Collumn Address
    writeCommand( 0x10 );

    // Set Start Line Address
    writeCommand( 0x40 );

    // Set Contrast
    writeCommand( 0x81 );
    writeCommand( 0xFF );

    // Set Segment Remap 0-127
    writeCommand( 0xA1 );

    // Set Normal Color
    writeCommand( 0xA6 );

    writeCommand( 0xA8 );

    writeCommand( 0x1F );

    // Output follows RAM content
    writeCommand( 0xA4 );

    // Set Display Offset
    writeCommand( 0xD3 );
    // NO Offset
    writeCommand( 0x00 );

    // Set Display Clock Divide Ratio/Osc. Freq
    writeCommand( 0xD5 );
    // Ratio
    writeCommand( 0xF0 );

    // Set Pre-charge Period
    writeCommand( 0xD9 );
    // Period
    writeCommand( 0x22 );

    // Set COM Pin Hardware Configuration
    writeCommand( 0xDA );

    // 32 pixel height
    writeCommand( 0x02 );

    // Set VCOMH
    writeCommand( 0xD8 );
    // 0.77 x VCC
    writeCommand( 0x20 );

    // Enable DC-DC
    writeCommand( 0x8D );
    writeCommand( 0x14 );

    // We have to wait a bit. The charge pump needs some
    // time to startup correctly.
    delay( 500 );

    // Turn on the display.
    displayOn();

    // Clear the display buffer.
    clear();

    return true;

}

void ssd1306::clear(){

    // Clear the display buffer.
    memset( buffer, 0, SSD1306_WIDTH * SSD1306_HEIGHT / 8 );
  
}

void ssd1306::update(){

    uint8_t i;

    // Write data to the display line by line.
    for( i = 0; i < ( SSD1306_HEIGHT / 8 ); i++ ){

        writeCommand( (uint8_t)0xB0 + i );
        writeCommand( (uint8_t)0x00 );
        writeCommand( (uint8_t)0x10 );
        writeData( &buffer[ (uint16_t)i * SSD1306_WIDTH ], SSD1306_WIDTH );
        
    }
        
}

void ssd1306::writeData( uint8_t* data, uint16_t dataSize ){

    uint16_t i;
    uint8_t sent;

    // Begin the transmission.
    Wire.beginTransmission( address );
    Wire.write( (uint8_t)0x40 );

    // On AVR we have to count the sent bytes, because
    // Wire library can only send 32 bytes at once.
    sent = 1;
    for( i = 0; i < dataSize; i++ ){

        // Check if we reached the limit of the buffer.
        if( sent >= 30 ){
            
            // If the buffer is full, we have to send everything
            // and start a new transaction.
            Wire.endTransmission();
            Wire.beginTransmission( address );
            Wire.write( (uint8_t)0x40 );
            sent = 1;
            
        }

        // Write the data.
        Wire.write( data[ i ] );
        sent++;

    }

    // Send the rest of the previous chunk.
    Wire.endTransmission();

}

void ssd1306::writeCommand( uint8_t command ){

    // Write the command byte.
    Wire.beginTransmission( address );
    Wire.write( (uint8_t)0x00 );
    Wire.write( command );
    Wire.endTransmission();
  
}

void ssd1306::displayOn(){

    writeCommand( 0xAF );

}

void ssd1306::displayOff(){

    writeCommand( 0xAE );

}

void ssd1306::setPixel( uint8_t x, uint8_t y ){

    // Check the boundaries of the coordinates.
    if( x >= SSD1306_WIDTH ){

        return;

    }

    if( y >= SSD1306_HEIGHT ){

        return;

    }

    // Set the pixel in the buffer.
    buffer[ x + ( y / 8 ) * SSD1306_WIDTH ] |= 1 << ( y % 8 );

}

void ssd1306::clearPixel( uint8_t x, uint8_t y ){

    // Check the boundaries of the coordinates.
    if( x >= SSD1306_WIDTH ){

    return;

    }

    if( y >= SSD1306_HEIGHT ){

    return;

    }

    // Clear the pixel in the buffer.
    buffer[ x + ( y / 8 ) * SSD1306_WIDTH ] &= ~( 1 << ( y % 8 ) );

}

void ssd1306::fillRect( uint8_t x, uint8_t y, uint8_t w, uint8_t h ){

    uint8_t x_iter;
    uint8_t y_iter;

    // Fill the pixels of the rectangle.
    for( x_iter = x; x_iter < ( x + w ); x_iter++ ){

        for( y_iter = y; y_iter < ( y + h ); y_iter++ ){

            setPixel( x_iter, y_iter );

        }

    }

}

void ssd1306::clearRect( uint8_t x, uint8_t y, uint8_t w, uint8_t h ){

    uint8_t x_iter;
    uint8_t y_iter;

    // Clear the pixels of the rectangle.
    for( x_iter = 0; x_iter < ( x + w ); x_iter++ ){

        for( y_iter = 0; y_iter < ( y + h ); y_iter++ ){

            clearPixel( x + x_iter, y + y_iter );

        }

    }

}

void ssd1306::writeCharacter( uint8_t c ){

    uint8_t i;
    uint8_t j;

    // The character bitmaps are stored in PROGMEM.
    // They have to be copied to a buffer before use.
    uint8_t characterData[5];

    // Copy the bitmap data to the buffer.
    // 32 has to be subtracted from the character to match the indexing.
    // Every bitmap is 5 byte wide and they have a sixth emty bar to separate
    // the characters.
    characterData[ 0 ] = pgm_read_byte_near( ASCII + (uint8_t)( c - 32 ) * 5 );
    characterData[ 1 ] = pgm_read_byte_near( ASCII + (uint8_t)( c - 32 ) * 5 + 1 );
    characterData[ 2 ] = pgm_read_byte_near( ASCII + (uint8_t)( c - 32 ) * 5 + 2 );
    characterData[ 3 ] = pgm_read_byte_near( ASCII + (uint8_t)( c - 32 ) * 5 + 3 );
    characterData[ 4 ] = pgm_read_byte_near( ASCII + (uint8_t)( c - 32 ) * 5 + 4 );
    
    // Process every byte.
    for( i = 0; i < 5; i++ ){

        // Process every bit in the byte.
        for( j = 0; j < 8; j++ ){

            // If not inverted and the bit is set, set the character.
            if( !!( characterData[ i ] & ( 1 << j ) ) ^ ( !!inverted ) ){

                setPixel( cursorX + i , cursorY + j );

            }

            // Else clear the character.
            else{

                clearPixel( cursorX + i , cursorY + j );

            }

        }

    }

    // In inverted case the separator bar has to be filled.
    if( inverted ){

        for( j = 0; j < 8; j++ ){

            setPixel( cursorX + i , cursorY + j );

        }

    }

    // Step the cursor.
    cursorX += 6;
    

    // If the cursor overflows jump to next line and reset the cursor.
    if( cursorX > 127 ){

        cursorX = 0;
        cursorY += 8;

    }

}

void ssd1306::print( char* str ){

    uint32_t i = 0;

    // Print every character in the string.
    while( str[ i ] ){

        writeCharacter( str[ i ] );
        i++;

    }

}

void ssd1306::print( int d ){

    char charBuffer[ 22 ];

    // Create a formatted string that contains the number and print it.
    snprintf( charBuffer, 22, "%d", d );

    print( charBuffer );

}

void ssd1306::line( uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2 ){

    // The good old Bresenham algorithm. He made a very elegant
    // solution for line drawing.
    int m_new = 2 * ( y2 - y1 );
    int slope_error_new = m_new - ( x2 - x1 );
    int x;
    int y = y1;

    for( x = x1; x <= x2; x++ ){

        if( inverted ){
            clearPixel( x, y );
        }

        else{
            setPixel( x, y );
        }

        slope_error_new += m_new;

        if( slope_error_new >= 0 ){

            y++;
            slope_error_new -= 2 * ( x2 - x1 );

        }

    }

}