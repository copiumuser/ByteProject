/*
CheckedArray.h
Zoey Anderson
Assignment 11 - Inheritance
7/14/2025
*/

#ifndef CHECKEDARRAY
#define CHECKEDARRAY

namespace zoey {

	class CheckedArray {
	private:
		int* ar = nullptr;
		int size;

	public:
		// accessors

		int at(int index) const;
		int operator[] (int index) const;
		int getSize() const;

		// mutators

		bool initialize(int size, int val = 0);
		void set(int index, int val);

		// constructors

		CheckedArray();
		CheckedArray(int size);
		CheckedArray(const CheckedArray& f);	// copy constructor needed to avoid double deletions with RandomByte

		// destructor

		~CheckedArray();
	};

}
#endif;		// unsure why but an error is thrown if there is no semicolon here
