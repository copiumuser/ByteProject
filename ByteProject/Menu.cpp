/*
Menu.cpp
Zoey Anderson
Assignment 8 - Namespaces
7/3/2025
*/

#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "Menu.h"

using namespace std;

namespace zoey {
	Menu* Menu::pInstance = nullptr;

	void Menu::addMenu(const char* description, void(*f)(void)) {
		MenuItem temp;
		temp.func = f;
		strcpy_s(temp.descript, description);
		mi.push_back(temp);
		count++;
	}

	void Menu::runMenu() {
		for (;;) {
			system("CLS");
			for (int i = 0; i < count; i++) {
				cout << this->mi[i].descript << endl;
			}
			runSelection();
		}
	}

	void Menu::runSelection() {
		int select;
		cin >> select;
		if (select <= count) {
			this->mi[select - 1].func();
		}
	}

	void  Menu::waitKey() {
		cout << "Press any key to continue" << endl;
		while (!_kbhit());
		fflush(stdin);
	}

	Menu* Menu::instance() {
		if (pInstance == nullptr) {
			pInstance = new Menu;
		}
		return pInstance;
	}
}