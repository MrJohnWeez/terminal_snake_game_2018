#include "KeyInput.h"
#include <vector>
#include <iostream>
#include <string>
#include <time.h>


using namespace std;

KeyInput _KeyInput;

bool runGame = true;

int main()
{
	clock_t begin;
	clock_t deltaTime = 0;
	while (runGame) {
		begin = clock();
		deltaTime += clock() - begin;
		// Set a string vector to all spaces then in the loop change the spaces to a # sign to make lines
		if (deltaTime > 30) {
			deltaTime = 0;
			cout << string(16, '\n') <<
				"_________________________________________________________________\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"_________________________________________________________________" << endl;
		}
		/*string currKey = _KeyInput.GetKey();
		if (currKey == "UP") {
			cout << string(16, '\n') <<
				"_________________________________________________________________\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"_________________________________________________________________" << endl;
		}
		else  {
			cout << string(16, '\n') <<
				"_________________________________________________________________\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                              |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"|                                                               |\n"
				"________________________HHHHHHHHHHHHHHHHH________________________" << endl;
		}*/
	}
	return 0;
}