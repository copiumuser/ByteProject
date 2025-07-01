/*
Byte.h
Zoey Anderson
Assignment 2 - Class Construction
6/11/2025
*/

#ifndef BYTE
#define BYTE

#include <string>

class Byte {
private:
	int bits[8];

	int bitsToInt();
public:
	void setValue(int value);
	int at(int index);
	std::string toString();
	int toInt();
};

#endif 

