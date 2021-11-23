#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

class Menu {
	private:
		string userInput;
	public:
		void start_game();
		void select_easy();
		void select_hard();
		void select_speed();
		bool toggle_powerups();
		void load_game();
        void menu();

};
#endif