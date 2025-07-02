/*
Menu.h
Zoey Anderson
Assignment 7 - Dynamic Memory
7/1/2025
*/

#ifndef MENU
#define MENU

#include <vector>

using std::vector;

struct MenuItem {
	void (*func)();
	char descript[50];
};

class Menu {
private:
	vector<MenuItem> mi;
	int count;
	void runSelection();

public:
	Menu();
	void addMenu(const char* description, void(*f)());
	void runMenu();
	void waitKey();
};

#endif