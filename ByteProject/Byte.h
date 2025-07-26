/*
Byte.h
Zoey Anderson
Assignment 14 - Templates
7/25/2025
*/

#ifndef BYTE
#define BYTE

#include <string>

#include "CheckedArray.h"

using std::string;

namespace zoey {
	class Byte : public CheckedArray<int> {
	private:
		int bitsToInt();
	public:
		void setValue(int value);
		string toString() const override;
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

		// constructors
		Byte();
		Byte(int val);
		Byte(int ar[]);
	};
}
#endif 

