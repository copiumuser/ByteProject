/*
Main.cpp
Zoey Anderson
Assignment 8 - Namespaces
7/3/2025
*/

#include <iostream>

#include "Menu.h"
#include "Byte.h"

namespace zoey {
	// declare byte and menu within zoey namespace to avoid global declaration and code duplication in menu
	Menu* m = Menu::instance();
	Byte* b = new Byte;
}

using namespace std;
using namespace zoey;

void setValue();
void at();
void equalTo();
void notEqualTo();
void add();
void sub();
void mul();
void div();

int main() {
	if (b == NULL) {
		cout << "Unable to allocate memory for Byte object" << endl;
		m->waitKey();
		return 0;
	}
	m->addMenu("1. SetValue", setValue);
	m->addMenu("2. At", at);
	m->addMenu("3. Equal To", equalTo);
	m->addMenu("4. Not Equal To", notEqualTo);
	m->addMenu("5. Add", add);
	m->addMenu("6. Sub", sub);
	m->addMenu("7. Mul", mul);
	m->addMenu("8. Div", div);

	m->runMenu();
	delete b;
	return 0;
}

void setValue() {
	int in;
	system("CLS");
	cout << "What would you like to set the value to?" << endl;
	cin >> in;
	b->setValue(in);
	cout << "The value has been set to:\nInt: " << b->toInt() << "\nString: " << b->toString() << endl;
	m->waitKey();
}

void at() {
	int in;
	system("CLS");
	cout << "What index would you like to see?" << endl;
	cin >> in;
	cout << "The value at " << in << " is " << b->at(in) << endl;
	m->waitKey();
}

void equalTo() {
	int in;
	char type;
	bool equal;
	Byte* temp;
	temp = new Byte;
	system("CLS");
	cout << "What value would you like to compare to?" << endl;
	cin >> in;
	cout << "Would you like to perform this operation with a complex or primitive type? (c/p)" << endl;
	cin >> type;
	type = tolower(type);
	switch (type) {
	case 'c':
		*temp = in;
		equal = *b == *temp;
		break;
	case 'p':
		equal = *b == in;
		break;
	default:
		cout << "Invalid Type Selection" << endl;
		m->waitKey();
		return;
	}
	cout << b->toInt() << " is ";
	if (!equal) {
		cout << "not ";
	}
	cout << "equal to " << in << endl;
	m->waitKey();
}

void notEqualTo() {
	int in;
	char type;
	bool equal;
	Byte* temp;
	temp = new Byte;
	system("CLS");
	cout << "What value would you like to compare to?" << endl;
	cin >> in;
	cout << "Would you like to perform this operation with a complex or primitive type? (c/p)" << endl;
	cin >> type;
	type = tolower(type);
	switch (type) {
	case 'c':
		*temp = in;
		equal = *b != *temp;
		break;
	case 'p':
		equal = *b != in;
		break;
	default:
		cout << "Invalid Type Selection" << endl;
		m->waitKey();
		return;
	}
	cout << b->toInt() << " is ";
	if (equal) {
		cout << "not ";
	}
	cout << "equal to " << in << endl;
	m->waitKey();
}

void add() {
	int in;
	char type;
	Byte* temp;
	temp = new Byte;
	system("CLS");
	cout << "What would you like to add?" << endl;
	cin >> in;
	cout << "Would you like to perform this operation with a complex or primitive type? (c/p)" << endl;
	cin >> type;
	type = tolower(type);
	switch (type) {
	case 'c':
		*temp = in;
		*b = (*b + *temp);
		break;
	case 'p':
		*b = *b + in;
		break;
	default:
		cout << "Invalid Type Selection" << endl;
		m->waitKey();
		return;
	}
	cout << "The value is now:\nInt: " << b->toInt() << "\nString: " << b->toString() << endl;
	m->waitKey();
}

void sub() {
	int in;
	char type;
	Byte* temp;
	temp = new Byte;
	system("CLS");
	cout << "What would you like to subtract?" << endl;
	cin >> in;
	cout << "Would you like to perform this operation with a complex or primitive type? (c/p)" << endl;
	cin >> type;
	type = tolower(type);
	switch (type) {
	case 'c':
		*temp = in;
		*b = *b - *temp;
		break;
	case 'p':
		*b = *b - in;
		break;
	default:
		cout << "Invalid Type Selection" << endl;
		m->waitKey();
		return;
	}
	cout << "The value is now:\nInt: " << b->toInt() << "\nString: " << b->toString() << endl;
	m->waitKey();
}

void mul() {
	int in;
	char type;
	Byte* temp;
	temp = new Byte;
	system("CLS");
	cout << "What would you like to multiply by?" << endl;
	cin >> in;
	cout << "Would you like to perform this operation with a complex or primitive type? (c/p)" << endl;
	cin >> type;
	type = tolower(type);
	switch (type) {
	case 'c':
		*temp = in;
		*b = *b * *temp;
		break;
	case 'p':
		*b = *b * in;
		break;
	default:
		cout << "Invalid Type Selection" << endl;
		m->waitKey();
		return;
	}
	cout << "The value is now:\nInt: " << b->toInt() << "\nString: " << b->toString() << endl;
	m->waitKey();
}

void div() {
	int in;
	char type;
	Byte* temp;
	temp = new Byte;
	system("CLS");
	cout << "What would you like to divide by?" << endl;
	cin >> in;
	cout << "Would you like to perform this operation with a complex or primitive type? (c/p)" << endl;
	cin >> type;
	type = tolower(type);
	switch (type) {
	case 'c':
		*temp = in;
		*b = *b / *temp;
		break;
	case 'p':
		*b = *b / in;
		break;
	default:
		cout << "Invalid Type Selection" << endl;
		m->waitKey();
		return;
	}
	cout << "The value is now:\nInt: " << b->toInt() << "\nString: " << b->toString() << endl;
	m->waitKey();
}