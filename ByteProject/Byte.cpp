/*
Byte.cpp
Zoey Anderson
Assignment 14 - Templates
7/25/2025
*/

#include <iostream>
#include <string>
#include <algorithm>

#include "Byte.h"

using namespace std;

namespace zoey {
	int Byte::bitsToInt() {
		int posValue = 1;
		int total = 0;

		try {
			for (int i = 0; i < 8; i++) {
				total += at(i) * posValue;	// increase the total by posValue if bits[i] = 1
				posValue *= 2;					// multiply the posValue by 2
			}
		}
		catch (string msg) {
			throw(msg);
		}

		return total;
	}

	void Byte::setValue(int value) {
		if (value > 255 || value < 0) {
			cout << "Value is outside the bounds of one unsigned byte" << endl;
			return;
		}

		for (int i = 0; i < 8; i++) {
			try {
				set(i, value & 1);	// check whether the first bit of value is 1
			}
			catch (string msg) {
				throw(msg);
			}
			value = value >> 1;		// shift value to the right by 1 (multiply the position value by 2)
		}
	}

	string Byte::toString() const {
		try {
			string temp = CheckedArray::toString();
			reverse(temp.begin(), temp.end());
			return temp;
		}
		catch (string msg) {
			throw(msg);
		}
	}

	int Byte::toInt() {
		return bitsToInt();
	}

	Byte Byte::add(int val) {
		return this->toInt() + val;
	}

	Byte Byte::sub(int val) {
		return this->toInt() - val;
	}

	Byte Byte::mul(int val) {
		return this->toInt() * val;
	}

	Byte Byte::div(int val) {
		return this->toInt() / val;
	}

	// operator overloads

	Byte Byte::operator+(const int f) {
		return this->add(f);
	}

	Byte Byte::operator+(Byte& f) {
		return this->add(f.toInt());
	}

	Byte Byte::operator-(const int f) {
		return this->sub(f);
	}

	Byte Byte::operator-(Byte& f) {
		return this->sub(f.toInt());
	}

	Byte Byte::operator*(const int f) {
		return this->mul(f);
	}

	Byte Byte::operator*(Byte& f) {
		return this->mul(f.toInt());
	}

	Byte Byte::operator/(const int f) {
		return this->div(f);
	}

	Byte Byte::operator/(Byte& f) {
		return this->div(f.toInt());
	}

	Byte Byte::operator=(const int f) {
		this->setValue(f);
		return *this;
	}

	Byte Byte::operator=(Byte f) {
		this->setValue(f.toInt());
		return *this;
	}

	bool Byte::operator==(const int f) {
		if (this->toInt() == f) {
			return true;
		}
		return false;
	}

	bool Byte::operator==(Byte& f) {
		if (this->toInt() == f.toInt()) {
			return true;
		}
		return false;
	}

	bool Byte::operator!=(const int f) {
		if (this->toInt() != f) {
			return true;
		}
		return false;
	}

	bool Byte::operator!=(Byte& f) {
		if (this->toInt() != f.toInt()) {
			return true;
		}
		return false;
	}

	Byte::Byte() : Byte(0) {}

	Byte::Byte(int val) : CheckedArray(8) {
		this->setValue(val);
	}

	Byte::Byte(int ar[]) : CheckedArray(8) {
		try {
			for (int i = 0; i < 8; i++) {
				if (ar[i] == 1 || ar[i] == 0) {		// input array verification
					set(7 - i, ar[i]);				// bits is reversed ar[]
				}
				else {
					cout << "Input array does not contain only 1s and 0s" << endl;
					return;
				}
			}
		}
		catch (string msg) {
			throw(msg);
		}
	}
}