/*
RandomByte.cpp
Zoey Anderson
Assignment 11 - Inheritance
7/14/2025
*/

#include <iostream>
#include <vector>
#include <random>

#include "Byte.h"
#include "RandomByte.h"

using namespace std;

namespace zoey {
	Byte RandomByte::nextByte() {
		Byte temp = bytes[VECTOR_SIZE - counter];
		counter++;
		if (counter >= RESHUFFLE_LIMIT) {
			this->shuffle();
		}
		return temp;
	}

	int RandomByte::nextInt() {
		Byte temp = bytes[VECTOR_SIZE - counter];
		counter++;
		if (counter >= RESHUFFLE_LIMIT) {
			this->shuffle();
		}
		return temp.toInt();
	}

	void RandomByte::setRange(int min, int max) {
		this->fillVect(min, max);
	}

	void RandomByte::setRange(Byte min, Byte max) {
		this->fillVect(min.toInt(), max.toInt());
	}

	// private functions

	void RandomByte::fillVect(int min, int max) {
		for (int i = 0; i < VECTOR_SIZE; i++) {
			uint8_t raw = static_cast<uint8_t>(rand() % max - min);		// max - min to generate in given range without offset
			raw = raw + min;	// adding min to offset raw to be between min and max
			bytes.push_back(Byte(raw));
		}
	}

	void RandomByte::shuffle() {
		cout << "Reshuffling" << endl;
		counter = 1;
		std::shuffle(bytes.begin(), bytes.end(), std::mt19937());
	}

	// constructors

	RandomByte::RandomByte() {
		counter = 1;
		srand(static_cast<unsigned>(time(nullptr)));
		this->fillVect(0, 256);
	}

	RandomByte::RandomByte(int min, int max) {
		counter = 1;
		srand(static_cast<unsigned>(time(nullptr)));
		this->setRange(min, max);	// set range also fills
	}

	RandomByte::RandomByte(Byte min, Byte max) {
		counter = 1;
		srand(static_cast<unsigned>(time(nullptr)));
		this->setRange(min, max);	// set range also fills
	}

	RandomByte::RandomByte(int seed) {
		counter = 1;
		srand(seed);
		this->fillVect(0, 256);
	}
}