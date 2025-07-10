/*
Menu.h
Zoey Anderson
Midterm
7/9/2025
*/

#ifndef MENU
#define MENU

#include <vector>

using std::vector;

namespace zoey {
	struct MenuItem {
		void (*func)();
		char descript[50];
	};

	class Menu {
	private:
		vector<MenuItem> mi;
		int count;
		void runSelection();
		static Menu* pInstance;

		Menu() : count(0) {}

	public:
		void addMenu(const char* description, void(*f)());
		void runMenu();
		void waitKey();

		static Menu* instance();
	};
}
#endif