/*
Main.cpp
Zoey Anderson
Assignment 4 - Vectors
6/17/2025
*/

#include <iostream>

#include "Menu.h"
#include "Byte.h"

using namespace std;

void setValue();
void add();
void sub();
void mul();
void div();

Menu m;
Byte b;

int main() {
	int temp[8] = { 1, 0, 1, 1, 0, 0, 0, 1 };
	Byte bAr(temp);
	cout << "Array constructor passing 10110001: \nInt: " << bAr.toInt() << "\nString: " << bAr.toString() << endl;
	m.waitKey();
	m.addMenu("1. SetValue", setValue);
	m.addMenu("2. Add", add);
	m.addMenu("3. Sub", sub);
	m.addMenu("4. Mul", mul);
	m.addMenu("5. Div", div);

	m.runMenu();
	return 0;
}

void setValue() {
	int in;
	system("CLS");
	cout << "What would you like to set the value to?" << endl;
	cin >> in;
	b.setValue(in);
	cout << "The value has been set to:\nInt: " << b.toInt() << "\nString: " << b.toString() << endl;
	m.waitKey();
}

void add() {
	int in;
	system("CLS");
	cout << "What would you like to add?" << endl;
	cin >> in;
	b = b.add(in);
	cout << "The value is now:\nInt: " << b.toInt() << "\nString: " << b.toString() << endl;
	m.waitKey();
}

void sub() {
	int in;
	system("CLS");
	cout << "What would you like to subtract?" << endl;
	cin >> in;
	b = b.sub(in);
	cout << "The value is now:\nInt: " << b.toInt() << "\nString: " << b.toString() << endl;
	m.waitKey();
}

void mul() {
	int in;
	system("CLS");
	cout << "What would you like to multiply by?" << endl;
	cin >> in;
	b = b.mul(in);
	cout << "The value is now:\nInt: " << b.toInt() << "\nString: " << b.toString() << endl;
	m.waitKey();
}

void div() {
	int in;
	system("CLS");
	cout << "What would you like to divide by?" << endl;
	cin >> in;
	b = b.div(in);
	cout << "The value is now:\nInt: " << b.toInt() << "\nString: " << b.toString() << endl;
	m.waitKey();
}