/*
Byte.h
Zoey Anderson
Assignment 3 - Overloaded Constructors
6/16/2025
*/

#ifndef BYTE
#define BYTE

#include <string>

using std::string;

class Byte {
private:
	int bits[8];

	int bitsToInt();
public:
	void setValue(int value);
	int at(int index);
	string toString();
	int toInt();

	Byte add(int val);
	Byte sub(int val);
	Byte mul(int val);
	Byte div(int val);

	// constructors
	Byte();
	Byte(int val);
	Byte(int ar[]);
};

#endif 

