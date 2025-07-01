/*
Main.cpp
Zoey Anderson
Assignment 2 - Class Construction
6/11/2025
*/

#include <iostream>

#include "Byte.h"

using namespace std;

int main() {
	Byte bite;

	cout << "\n99: \n" << endl;
	bite.setValue(99);

	for (int i = 0; i < 8; i++) {
		cout << bite.at(i) << endl;
	}
	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	cout << "\n147: \n" << endl;
	bite.setValue(147);

	for (int i = 0; i < 8; i++) {
		cout << bite.at(i) << endl;
	}
	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	cout << "\n0: \n" << endl;
	bite.setValue(0);

	for (int i = 0; i < 8; i++) {
		cout << bite.at(i) << endl;
	}
	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	cout << "\n255: \n" << endl;
	bite.setValue(255);

	for (int i = 0; i < 8; i++) {
		cout << bite.at(i) << endl;
	}
	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	cout << "\n-1: \n" << endl;
	bite.setValue(-1);

	for (int i = 0; i < 8; i++) {
		cout << bite.at(i) << endl;
	}
	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	cout << "\n256: \n" << endl;
	bite.setValue(256);

	for (int i = 0; i < 8; i++) {
		cout << bite.at(i) << endl;
	}
	cout << "Int:    " << bite.toInt() << endl;
	cout << "String: " << bite.toString() << endl;

	return 0;
}