/*
Byte.h
Zoey Anderson
Assignment 4 - Vectors
6/17/2025
*/

#ifndef BYTE
#define BYTE

#include <string>
#include <vector>

using std::string;
using std::vector;

class Byte {
private:
	vector<int> bits;

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

