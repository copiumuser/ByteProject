/*
Main.cpp
Zoey Anderson
Midterm
7/9/2025
*/

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <ostream>
#include <fstream>

#include "Menu.h"
#include "Byte.h"
#include "RandomByte.h"

namespace zoey {
	// declare byte and menu within zoey namespace to avoid global declaration and code duplication in menu
	Menu* m = Menu::instance();
	Byte* b = new Byte;
	RandomByte* rB = new RandomByte;
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
void generateNRandomBytes();
void randomByteMathDemo();
void randomByteStatistics(); 
void generateRandom();
void parseFile();

int main() {
	srand(static_cast<unsigned int>(time(0)));
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
	m->addMenu("9. Generate N Random Bytes", generateNRandomBytes);
	m->addMenu("10. Random Byte Math Demo", randomByteMathDemo);
	m->addMenu("11. Random Byte Statistics", randomByteStatistics);
	m->addMenu("12. Generate Random", generateRandom);
	m->addMenu("13. Parse File", parseFile);


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

void generateNRandomBytes() {
	int in;
	system("CLS");
	cout << "What would you like to set N to?" << endl;
	cin >> in;
	for (int i = 0; i < in; i++) {
		Byte temp = rB->nextByte();
		cout << "\nN: " << i << "\nInt: " << temp.toInt() << "\nString: " << temp.toString() << endl;
	}
	m->waitKey();
}

void randomByteMathDemo() {
	int temp1 = rB->nextInt();
	int temp2 = rB->nextInt();
	cout << "Byte 1: " << temp1 << "\nByte 2: " << temp2 << endl;
	cout << "Byte 1 + Byte 2 = " << temp1 + temp2 << endl;
	cout << "Byte 1 - Byte 2 = " << temp1 - temp2 << endl;
	cout << "Byte 1 * Byte 2 = " << temp1 * temp2 << endl;
	cout << "Byte 1 / Byte 2 = " << temp1 / temp2 << endl;
	m->waitKey();
}

void randomByteStatistics() {
	int in;
	double average = 0;
	int min = 999999999;	// set very high so it will be greater than the set range
	int max = 0;
	int ones = 0;
	int zeros = 0;
	system("CLS");
	cout << "What would you like to set N to?" << endl;
	cin >> in;
	for (int i = 0; i < in; i++) {
		Byte temp = rB->nextByte();
		if (temp.toInt() <= min) {
			min = temp.toInt();
		}
		if (temp.toInt() >= max) {
			max = temp.toInt();
		}
		average += temp.toInt();
		average /= 2;
		string tempStr = temp.toString();
		for (int i = 0; i < tempStr.length(); i++) {
			if (tempStr[i] == '1') {
				ones++;
			}
			else {
				zeros++;
			}
		}
	}
	cout << "Minimum: " << min << "\nMaximum: " << max << "\nAverage: " << average <<
		"\nTotal Ones: " << ones << "\nTotal Zeros: " << zeros << endl;
	m->waitKey();
}

void generateRandom() {
	ofstream outFile("Numbers.txt");
	if (!outFile) {
		cout << "Unable to open file to write" << endl;
	}
	for (int i = 0; i < 100; i++) {
		double r = (((double)rand() / (double)RAND_MAX) * (250 - 1)) + 1;
		outFile << r << endl;
	}
	outFile.close();
	m->waitKey();
}

void parseFile() {
	vector<int> nums;
	ifstream inFile("Numbers.txt");
	if (!inFile) {
		cout << "Unable to open file to read" << endl;
	}
	string in;
	while (inFile >> in) {
		in = in.substr(0, in.find_first_of("."));
		nums.push_back(stoi(in));
	}
	inFile.close();

	ofstream outFile("Binary.txt");
	if (!outFile) {
		cout << "Unable to open file to write" << endl;
	}
	int numsSize = nums.size();
	for (int i = 0; i < numsSize; i++) {
		Byte temp(nums.back());
		nums.pop_back();
		outFile << temp.toInt() << " - binary: " << temp.toString() << endl;
	}
	outFile.close();
	m->waitKey();
}