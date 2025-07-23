/*
CheckedArray.h
Zoey Anderson
Assignment 13 - Exceptions
7/22/2025
*/

#ifndef CHECKEDARRAY
#define CHECKEDARRAY

#include <exception>

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

	class CheckedArrayException : public std::exception {
	private:
		std::string message;

	public:
		const char* what() const override;

		// constructors

		CheckedArrayException() : CheckedArrayException("Checked Array Error") {}
		CheckedArrayException(std::string inMessage);
	};

}
#endif;		// unsure why but an error is thrown if there is no semicolon here
