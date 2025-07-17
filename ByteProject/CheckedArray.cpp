/*
Main.cpp
Zoey Anderson
Assignment 12 - Polymorphism
7/17/2025
*/

#include <iostream>
#include <string>

#include "CheckedArray.h"

using namespace std;
using namespace zoey;

// accessors

int CheckedArray::at(int index) const {
	if (index < this->getSize() && index >= 0 && ar != nullptr) {
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

string CheckedArray::toString() const {
	string temp = "";
	for (int i = 0; i < this->getSize(); i++) {
		temp += to_string(ar[i]);
	}
	return temp;
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