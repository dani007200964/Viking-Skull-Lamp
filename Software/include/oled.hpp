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

#ifndef OLED_HPP__
#define OLED_HPP__

#include "Arduino.h"
#include "Wire.h"
#include "stdint.h"

/// Width of the display module in pixels.
#define SSD1306_WIDTH 128

/// Height of the display module in pixels.
#define SSD1306_HEIGHT 32

/// Font for the display.
///
/// Every printable character have an 8 pixel heigh, 5 pixel wide bitmap.
/// The printable characters are start with 0x20 ( 32 in decimal ), this
/// is a space character.
const uint8_t ASCII[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00  // 0x20 Space
    ,0x00, 0x00, 0x5f, 0x00, 0x00 // 0x21 !
    ,0x00, 0x07, 0x00, 0x07, 0x00 // 0x22 "
    ,0x14, 0x7f, 0x14, 0x7f, 0x14 // 0x23 #
    ,0x24, 0x2a, 0x7f, 0x2a, 0x12 // 0x24 $
    ,0x23, 0x13, 0x08, 0x64, 0x62 // 0x25 %
    ,0x36, 0x49, 0x55, 0x22, 0x50 // 0x26 &
    ,0x00, 0x05, 0x03, 0x00, 0x00 // 0x27 '
    ,0x00, 0x1c, 0x22, 0x41, 0x00 // 0x28 (
    ,0x00, 0x41, 0x22, 0x1c, 0x00 // 0x29 )
    ,0x14, 0x08, 0x3e, 0x08, 0x14 // 0x2a *
    ,0x08, 0x08, 0x3e, 0x08, 0x08 // 0x2b +
    ,0x00, 0x50, 0x30, 0x00, 0x00 // 0x2c ,
    ,0x08, 0x08, 0x08, 0x08, 0x08 // 0x2d -
    ,0x00, 0x60, 0x60, 0x00, 0x00 // 0x2e .
    ,0x20, 0x10, 0x08, 0x04, 0x02 // 0x2f /
    ,0x3e, 0x51, 0x49, 0x45, 0x3e // 0x30 0
    ,0x00, 0x42, 0x7f, 0x40, 0x00 // 0x31 1
    ,0x42, 0x61, 0x51, 0x49, 0x46 // 0x32 2
    ,0x21, 0x41, 0x45, 0x4b, 0x31 // 0x33 3
    ,0x18, 0x14, 0x12, 0x7f, 0x10 // 0x34 4
    ,0x27, 0x45, 0x45, 0x45, 0x39 // 0x35 5
    ,0x3c, 0x4a, 0x49, 0x49, 0x30 // 0x36 6
    ,0x01, 0x71, 0x09, 0x05, 0x03 // 0x37 7
    ,0x36, 0x49, 0x49, 0x49, 0x36 // 0x38 8
    ,0x06, 0x49, 0x49, 0x29, 0x1e // 0x39 9
    ,0x00, 0x36, 0x36, 0x00, 0x00 // 0x3a :
    ,0x00, 0x56, 0x36, 0x00, 0x00 // 0x3b ;
    ,0x08, 0x14, 0x22, 0x41, 0x00 // 0x3c <
    ,0x14, 0x14, 0x14, 0x14, 0x14 // 0x3d =
    ,0x00, 0x41, 0x22, 0x14, 0x08 // 0x3e >
    ,0x02, 0x01, 0x51, 0x09, 0x06 // 0x3f ?
    ,0x32, 0x49, 0x79, 0x41, 0x3e // 0x40 @
    ,0x7e, 0x11, 0x11, 0x11, 0x7e // 0x41 A
    ,0x7f, 0x49, 0x49, 0x49, 0x36 // 0x42 B
    ,0x3e, 0x41, 0x41, 0x41, 0x22 // 0x43 C
    ,0x7f, 0x41, 0x41, 0x22, 0x1c // 0x44 D
    ,0x7f, 0x49, 0x49, 0x49, 0x41 // 0x45 E
    ,0x7f, 0x09, 0x09, 0x09, 0x01 // 0x46 F
    ,0x3e, 0x41, 0x49, 0x49, 0x7a // 0x47 G
    ,0x7f, 0x08, 0x08, 0x08, 0x7f // 0x48 H
    ,0x00, 0x41, 0x7f, 0x41, 0x00 // 0x49 I
    ,0x20, 0x40, 0x41, 0x3f, 0x01 // 0x4a J
    ,0x7f, 0x08, 0x14, 0x22, 0x41 // 0x4b K
    ,0x7f, 0x40, 0x40, 0x40, 0x40 // 0x4c L
    ,0x7f, 0x02, 0x0c, 0x02, 0x7f // 0x4d M
    ,0x7f, 0x04, 0x08, 0x10, 0x7f // 0x4e N
    ,0x3e, 0x41, 0x41, 0x41, 0x3e // 0x4f O
    ,0x7f, 0x09, 0x09, 0x09, 0x06 // 0x50 P
    ,0x3e, 0x41, 0x51, 0x21, 0x5e // 0x51 Q
    ,0x7f, 0x09, 0x19, 0x29, 0x46 // 0x52 R
    ,0x46, 0x49, 0x49, 0x49, 0x31 // 0x53 S
    ,0x01, 0x01, 0x7f, 0x01, 0x01 // 0x54 T
    ,0x3f, 0x40, 0x40, 0x40, 0x3f // 0x55 U
    ,0x1f, 0x20, 0x40, 0x20, 0x1f // 0x56 V
    ,0x3f, 0x40, 0x38, 0x40, 0x3f // 0x57 W
    ,0x63, 0x14, 0x08, 0x14, 0x63 // 0x58 X
    ,0x07, 0x08, 0x70, 0x08, 0x07 // 0x59 Y
    ,0x61, 0x51, 0x49, 0x45, 0x43 // 0x5a Z
    ,0x00, 0x7f, 0x41, 0x41, 0x00 // 0x5b [
    ,0x02, 0x04, 0x08, 0x10, 0x20 // 0x5c backslash
    ,0x00, 0x41, 0x41, 0x7f, 0x00 // 0x5d ]
    ,0x04, 0x02, 0x01, 0x02, 0x04 // 0x5e ^
    ,0x40, 0x40, 0x40, 0x40, 0x40 // 0x5f _
    ,0x00, 0x01, 0x02, 0x04, 0x00 // 0x60 `
    ,0x20, 0x54, 0x54, 0x54, 0x78 // 0x61 a
    ,0x7f, 0x48, 0x44, 0x44, 0x38 // 0x62 b
    ,0x38, 0x44, 0x44, 0x44, 0x20 // 0x63 c
    ,0x38, 0x44, 0x44, 0x48, 0x7f // 0x64 d
    ,0x38, 0x54, 0x54, 0x54, 0x18 // 0x65 e
    ,0x08, 0x7e, 0x09, 0x01, 0x02 // 0x66 f
    ,0x0c, 0x52, 0x52, 0x52, 0x3e // 0x67 g
    ,0x7f, 0x08, 0x04, 0x04, 0x78 // 0x68 h
    ,0x00, 0x44, 0x7d, 0x40, 0x00 // 0x69 i
    ,0x20, 0x40, 0x44, 0x3d, 0x00 // 0x6a j
    ,0x7f, 0x10, 0x28, 0x44, 0x00 // 0x6b k
    ,0x00, 0x41, 0x7f, 0x40, 0x00 // 0x6c l
    ,0x7c, 0x04, 0x18, 0x04, 0x78 // 0x6d m
    ,0x7c, 0x08, 0x04, 0x04, 0x78 // 0x6e n
    ,0x38, 0x44, 0x44, 0x44, 0x38 // 0x6f o
    ,0x7c, 0x14, 0x14, 0x14, 0x08 // 0x70 p
    ,0x08, 0x14, 0x14, 0x18, 0x7c // 0x71 q
    ,0x7c, 0x08, 0x04, 0x04, 0x08 // 0x72 r
    ,0x48, 0x54, 0x54, 0x54, 0x20 // 0x73 s
    ,0x04, 0x3f, 0x44, 0x40, 0x20 // 0x74 t
    ,0x3c, 0x40, 0x40, 0x20, 0x7c // 0x75 u
    ,0x1c, 0x20, 0x40, 0x20, 0x1c // 0x76 v
    ,0x3c, 0x40, 0x30, 0x40, 0x3c // 0x77 w
    ,0x44, 0x28, 0x10, 0x28, 0x44 // 0x78 x
    ,0x0c, 0x50, 0x50, 0x50, 0x3c // 0x79 y
    ,0x44, 0x64, 0x54, 0x4c, 0x44 // 0x7a z
    ,0x00, 0x08, 0x36, 0x41, 0x00 // 0x7b {
    ,0x00, 0x00, 0x7f, 0x00, 0x00 // 0x7c |
    ,0x00, 0x41, 0x36, 0x08, 0x00 // 0x7d }
    ,0x10, 0x08, 0x08, 0x10, 0x08 // 0x7e ~
    ,0x78, 0x46, 0x41, 0x46, 0x78 // 0x7f DEL
    ,0x00, 0x3c, 0x7e, 0xe7, 0xc3 // 0x80 Half circle left
    ,0xc3, 0xe7, 0x7e, 0x3c, 0x00 // 0x81 Half circle right
    ,0x00, 0x3c, 0x7e, 0xFF, 0xFF // 0x82 Half full circle left
    ,0xFF, 0xFF, 0x7e, 0x3c, 0x00 // 0x83 Half full circle right
};

/// Display driver object.
///
/// This is a very optimized driver for the SSD1306 oled display driver.
/// It uses ideas from lot other libraries, but it has been optimized
/// to fit in this project. 
class ssd1306{

public:

    /// Constructor
    /// @param address_p I2C address of the display.
    ssd1306( uint8_t address_p );

    /// Init function for the display.
    /// @returns Returns true if the init section succeeds.
    bool begin();

    /// Turn on the oled panel.
    void displayOn();

    /// Turn off the oled panel.
    void displayOff();

    /// Update the content of the panel.
    ///
    /// It writes the content of the buffer to the display.
    /// @warning Changes on the display will only be visible after calling this function.
    void update();

    /// Set a pixel by location.
    /// @param x X-coordinate of the pixel.
    /// @param y Y-coordinate of the pixel.
    void setPixel( uint8_t x, uint8_t y );

    /// Clear a pixel by location.
    /// @param x X-coordinate of the pixel.
    /// @param y Y-coordinate of the pixel.
    void clearPixel( uint8_t x, uint8_t y );

    /// Create a filled rectangle.
    /// @param x X-coordinate of the start corner.
    /// @param y Y-coordinate of the start corner.
    /// @param w Width of the rectangle.
    /// @param h Height of the rectangle.
    void fillRect( uint8_t x, uint8_t y, uint8_t w, uint8_t h );

    /// Create a cleared rectangle.
    /// @param x X-coordinate of the start corner.
    /// @param y Y-coordinate of the start corner.
    /// @param w Width of the rectangle.
    /// @param h Height of the rectangle.
    void clearRect( uint8_t x, uint8_t y, uint8_t w, uint8_t h );

    /// Write a character to the display.
    /// @note The cursor has to be set before this function.
    /// @param c Character to write.
    void writeCharacter( uint8_t c );

    /// Clear the display.
    void clear();

    /// Print a c-string tho the display.
    /// @note The cursor has to be set before this function.
    /// @param str C-like string, that will be printed on the display.
    void print( char* str );

    /// Print number to the display.
    /// @note The cursor has to be set before this function.
    /// @param d The number, that has o be printed on the display.
    void print( int d );

    /// Print line to the display.
    /// @param x1 X-coordinate of the start point.
    /// @param y1 Y-coordinate of the start point.
    /// @param x2 X-coordinate of the end point.
    /// @param y2 Y-coordinate of the end point.
    void line( uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2 );

    /// If this flag is set, the draw logic will be inverted.
    /// That means set is black pixel, clear is lit pixel.
    bool inverted = false;

    /// X-coordinate of the cursor.
    uint8_t cursorX = 0;

    /// Y-coordinate of the cursor.
    uint8_t cursorY = 0;


private:

    /// Pixel buffer.
    uint8_t buffer[ SSD1306_WIDTH * SSD1306_HEIGHT / 8 ] = { 0 };

    /// Write data to the display.
    /// @param data Pointer to a byte array, that will be sent as data.
    /// @param dataSize Size of the byte array.
    void writeData( uint8_t* data, uint16_t dataSize );

    /// Write command to the display.
    /// @param c Command byte
    void writeCommand( uint8_t c );

    /// Address of the display.
    uint8_t address = 0;
  
};


#endif