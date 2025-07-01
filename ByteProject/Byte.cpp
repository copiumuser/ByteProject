/*
Byte.cpp
Zoey Anderson
Assignment 2 - Class Construction
6/11/2025
*/

#include <iostream>
#include <string>

#include "Byte.h"

using namespace std;

int Byte::bitsToInt() {
	int posValue = 1;
	int total = 0;

	for (int i = 0; i < 8; i++) {
		total += bits[i] * posValue;	// increase the total by posValue if bits[i] = 1
		posValue *= 2;					// multiply the posValue by 2
	}

	return total;
}

void Byte::setValue(int value) {
	if (value > 255 || value < 0) {
		cout << "Value is outside the bounds of one unsigned byte" << endl;
		return;
	}

	for (int i = 0; i < 8; i++) {
		bits[i] = value & 1;	// check whether the first bit of value is 1
		value = value >> 1;		// shift value to the right by 1 (multiply the position value by 2)
	}
}

int Byte::at(int index) {
	return bits[index];
}

string Byte::toString() {
	string out = "";

	for (int i = 7; i > -1; i--) {		// loop is counting down to reverse the order of the bits[] values
		out += to_string(bits[i]);
	}

	return out;
}

int Byte::toInt() {
	return bitsToInt();
}