/*
Main.cpp
Zoey Anderson
Assignment 12 - Polymorphism
7/17/2025
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

		virtual int at(int index) const;
		virtual int operator[] (int index) const;
		virtual std::string toString() const;
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
