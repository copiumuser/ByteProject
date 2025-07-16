/*
Byte.h
Zoey Anderson
Assignment 11 - Inheritance
7/14/2025
*/

#ifndef BYTE
#define BYTE

#include <string>

#include "CheckedArray.h"

using std::string;

namespace zoey {
	class Byte : public CheckedArray {
	private:
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

		// operator overloads
		Byte operator+ (const int f);
		Byte operator+ (Byte& f);

		Byte operator- (const int f);
		Byte operator- (Byte& f);

		Byte operator* (const int f);
		Byte operator* (Byte& f);

		Byte operator/ (const int f);
		Byte operator/ (Byte& f);

		Byte operator= (const int f);
		Byte operator= (Byte f);

		bool operator== (const int f);
		bool operator== (Byte& f);

		bool operator!= (const int f);
		bool operator!= (Byte& f);

		int operator[] (const int f);

		// constructors
		Byte();
		Byte(int val);
		Byte(int ar[]);
	};
}
#endif 

