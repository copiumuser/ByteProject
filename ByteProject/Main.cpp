/*
Main.cpp
Zoey Anderson
Assignment 3 - Overloaded Constructors
6/16/2025
*/

#include <iostream>

#include "Byte.h"

using namespace std;

int main() {
	int testAr[8] = { 1, 1, 0, 0, 0, 1, 1, 0 };
	Byte biteDef;
	Byte biteInt(77);
	Byte biteAr(testAr);

	cout << "Default Constructor" << endl;
	cout << "Int: " << biteDef.toInt() << endl;
	cout << "String: " << biteDef.toString() << endl;

	cout << "\nInteger Constructor Passing 77" << endl;
	cout << "Int: " << biteInt.toInt() << endl;
	cout << "String: " << biteInt.toString() << endl;

	cout << "\nArray Constructor Passing 11000110" << endl;
	cout << "Int: " << biteAr.toInt() << endl;
	cout << "String: " << biteAr.toString() << endl;
	return 0;
}