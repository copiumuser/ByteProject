/*
RandomByte.h
Zoey Anderson
Assignment 14 - Templates
7/25/2025
*/

#ifndef RANDOMBYTE
#define RANDOMBYTE

#include <vector>

#include "Byte.h"

using std::vector;

namespace zoey {
	class RandomByte {
	private:
		vector<Byte> bytes;
		int counter;	// using a counter to count back through bytes instead of deleting so
		// that shuffling doesn't need to generate new numbers which would require storing the min and max vals
		static int constexpr  VECTOR_SIZE = 256;
		static int constexpr  RESHUFFLE_LIMIT = VECTOR_SIZE * 9 / 10;

		// private functions
		void fillVect(int min, int max);
		void shuffle();
	public:
		Byte nextByte();
		int nextInt();
		void setRange(int min, int max);
		void setRange(Byte min, Byte max);

		// constructors
		RandomByte();
		RandomByte(int min, int max);
		RandomByte(Byte min, Byte max);
		RandomByte(int seed);
	};
}
#endif
