/*
CheckedArray.h
Zoey Anderson
Assignment 14 - Templates
7/25/2025
*/

#ifndef CHECKEDARRAY
#define CHECKEDARRAY

#include <iostream>
#include <string>
#include <exception>

using std::string;

namespace zoey {
	template <typename T>
	class CheckedArray {
	private:
		T* ar = nullptr;
		T size;

	public:
		// accessors

		virtual T at(int index) const;
		virtual T operator[] (int index) const;
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

	template <typename T>
	class CheckedArrayException : public std::exception {
	private:
		std::string message;

	public:
		const char* what() const override;

		// constructors

		CheckedArrayException() : CheckedArrayException("Checked Array Error") {}
		CheckedArrayException(std::string inMessage);
	};

	// accessors

	template <typename T>
	T CheckedArray<T>::at(int index) const {
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

	template <typename T>
	T CheckedArray<T>::operator[] (int index) const {
		return this->at(index);
	}

	template <typename T>
	int CheckedArray<T>::getSize() const {
		return this->size;
	}

	template <typename T>
	string CheckedArray<T>::toString() const {
		string temp = "";
		for (int i = 0; i < this->getSize(); i++) {
			temp += std::to_string(ar[i]);
		}
		return temp;
	}

	// mutators

	template <typename T>
	bool CheckedArray<T>::initialize(int size, int val) {
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

	template <typename T>
	void CheckedArray<T>::set(int index, int val) {
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

	template <typename T>
	CheckedArray<T>::CheckedArray() : CheckedArray(10) {}

	template <typename T>
	CheckedArray<T>::CheckedArray(int size) {
		if (!this->initialize(size)) {
			throw string("Unable to Allocate Memory");
		}
	}

	template <typename T>
	CheckedArray<T>::CheckedArray(const CheckedArray& f) : CheckedArray(f.getSize()) {
		for (int i = 0; i < f.getSize(); i++) {
			this->set(i, f[i]);
		}
	}

	// destructor

	template <typename T>
	CheckedArray<T>::~CheckedArray() {
		if (ar != nullptr) {
			delete[] ar;
			ar = nullptr;
		}
	}

	// Checked Array Exception

	template <typename T>
	const char* CheckedArrayException<T>::what() const {
		return this->message.c_str();
	}

	// constructors

	template <typename T>
	CheckedArrayException<T>::CheckedArrayException(string inMessage) {
		this->message = inMessage;
	}
}
#endif;		// unsure why but an error is thrown if there is no semicolon here
