/*
CheckedArray.cpp
Zoey Anderson
Assignment 11 - Inheritance
7/14/2025
*/

#include <iostream>

#include "CheckedArray.h"

using namespace std;
using namespace zoey;

// accessors

int CheckedArray::at(int index) const {
	if (index < this->size && ar != nullptr) {
		return ar[index];
	}
	return 0;
}

int CheckedArray::operator[] (int index) const{
	return this->at(index);
}

int CheckedArray::getSize() const {
	return this->size;
}

// mutators

bool CheckedArray::initialize(int size, int val) {
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
	if (index <= this->size && ar != nullptr) {
		ar[index] = val;
	}
	return;
}

// constructors

CheckedArray::CheckedArray() : CheckedArray(10) {}

CheckedArray::CheckedArray(int size) {
	if (!this->initialize(size)) {
		cout << "Unable to allocate memory" << endl;
	}
}

CheckedArray::CheckedArray(const CheckedArray& f) {
	if (!this->initialize(f.getSize())) {
		cout << "Unable to allocate memory" << endl;
	}
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