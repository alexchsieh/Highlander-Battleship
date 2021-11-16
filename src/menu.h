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
		void powerups_on_or_off();
		void load_game();
		int main();

};
