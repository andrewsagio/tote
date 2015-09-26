/*
Copyright (c) 2014 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "IRLremote.h"

//================================================================================
// User function helper
//================================================================================

// ensure available() returns false
uint8_t  IRLProtocol = 0;
uint16_t IRLAddress = 0;
uint32_t IRLCommand = 0;

// Called when directly received correct IR Signal
// Do not use Serial inside, it can crash your Arduino!
void IREvent(uint8_t protocol, uint16_t address, uint32_t command) {
	// For no user function set we need to pause IR
	// to not overwrite the actual values until they are read.
	if (IRLProtocol) return;
	IRLAddress = address;
	IRLCommand = command;
	IRLProtocol = protocol;
}

void decodeIR(const uint16_t duration){
	// add your own protocols here or create your own decoding function
	// you can overwrite this function in your .ino file
	decodeAll(duration);
}
