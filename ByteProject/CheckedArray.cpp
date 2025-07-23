/*
CheckedArray.cpp
Zoey Anderson
Assignment 13 - Exceptions
7/22/2025
*/

#include <iostream>
#include <string>
#include <exception>

#include "CheckedArray.h"

using namespace std;
using namespace zoey;

// accessors

int CheckedArray::at(int index) const {
	if (index < this->getSize() && index >= 0) {	// nested if statements for accurate error messages
		if (ar != nullptr) {
			return ar[index];
		}
		else {
			throw string("Array is Null");
		}
	} 
	else {
		throw string("Index is out of Bounds");
	}
	return 0;
}

int CheckedArray::operator[] (int index) const{
	return this->at(index);
}

int CheckedArray::getSize() const {
	return this->size;
}

string CheckedArray::toString() const {
	string temp = "";
	for (int i = 0; i < this->getSize(); i++) {
		temp += to_string(ar[i]);
	}
	return temp;
}

// mutators

bool CheckedArray::initialize(int size, int val) {
	if (size <= 0) {	// check for valid size
		return false;
	}
	if (ar != nullptr) {
		delete[] ar;
		ar = nullptr;
	}
	ar = new int[size];
	if (ar == nullptr) {
		this->size = 0;
		return false;
	}
	for (int i = 0; i < size; i++) {
		ar[i] = val;
	}
	this->size = size;
	return true;
}

void CheckedArray::set(int index, int val) {
	if (index < this->getSize() && index >= 0) {	// nested if statements for accurate error messages
		if (ar != nullptr) {
			ar[index] = val;
			return;
		}
		else {
			throw string("Array is Null");
		}
	}
	else {
		throw string("Index is out of Bounds");
	}
	return;
}

// constructors

CheckedArray::CheckedArray() : CheckedArray(10) {}

CheckedArray::CheckedArray(int size) {
	if (!this->initialize(size)) {
		throw string("Unable to Allocate Memory");
	}
}

CheckedArray::CheckedArray(const CheckedArray& f) : CheckedArray(f.getSize()) {
	for (int i = 0; i < f.getSize(); i++) {
		this->set(i, f[i]);
	}
}

// destructor

CheckedArray::~CheckedArray() {
    if (ar != nullptr) {
        delete[] ar;
        ar = nullptr;
    }
}

// Checked Array Exception

const char* CheckedArrayException::what() const {
	return this->message.c_str();
}

// constructors

CheckedArrayException::CheckedArrayException(string inMessage) {
	this->message = inMessage;
}