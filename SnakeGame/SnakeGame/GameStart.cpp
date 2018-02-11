#include "KeyInput.h"
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <deque>

#define XLENGTH 41
#define YLENGTH 20
#define FXLENGTH 2 + XLENGTH
#define FYLENGTH 2 + YLENGTH


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_R 114
#define KEY_ENTER 13



int sx = (FXLENGTH / 2)+1;
int sy = FYLENGTH / 2;
int score = 0;
int fx;
int fy;

using namespace std;

string display[FYLENGTH][FXLENGTH];

KeyInput _KeyInput;

bool runGame = true;
int tempSize = 0;
int tailLength = 0;
bool gameRunning = false;
struct cord {
	int x;
	int y;
	cord(int inx, int iny) {
		x = inx;
		y = iny;
	}
};

void Draw()
{
	system("cls");
	for (int row = 0; row < FYLENGTH; row++) {
		for (int col = 0; col < FXLENGTH; col++) {
			cout << display[row][col];
		}
		cout << endl;
	}
	cout << "Score: " << score;
	
}
int randomInt(int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;

}

deque<cord> trail;

int main()
{
	for (int row = 0; row < FYLENGTH; row++) {
		for (int col = 0; col < FXLENGTH; col++) {
			if (row == 0 || col == FXLENGTH -1 || row == FYLENGTH -1 || col == 0) {
				display[row][col] = "#";
			}
			else {
				display[row][col] = " ";
			}
		}
	}
	display[sy][sx] = "0";
	fx = randomInt(1, FXLENGTH - 2);
	if (fx % 2 != 1) {
		fx++;
	}
	fy = randomInt(1, FYLENGTH - 2);
	display[fy][fx] = "*";


	clock_t begin;
	clock_t deltaTime = 0;
	string currKey = "";
	int preCode = -1;
	int c = 0;
	int ydir = 0;
	int xdir = 0;
	while (runGame) {
		begin = clock();
		
		string c = _KeyInput.GetKey();
		if(c != "") gameRunning = true;
		if (c == "UP") {
			ydir = 1;
			xdir = 0;
		}
		else if (c == "DOWN") {
			ydir = -1;
			xdir = 0;
		}
		else if (c == "LEFT") {
			ydir = 0;
			xdir = -1;
		}
		else if (c == "RIGHT") {
			ydir = 0;
			xdir = 1;
		}
		else if (c == "ESC") {
			runGame = false;
		}


		deltaTime += clock() - begin;
		
		if (deltaTime > 60) {
			deltaTime = 0;
			display[sy][sx] = "o";
			trail.push_front(cord(sx, sy));
			if (ydir > 0) {
				sy--;
			}
			else if (ydir < 0) {
				sy++;
			}
			else if (xdir > 0) {
				sx += 2;
			}
			else if (xdir < 0) {
				sx -= 2;
			}

			if (sy < 1) {
				sy = FYLENGTH - 2;
			}
			else if (sx < 1) {
				sx = FXLENGTH - 2;
			}
			else if (sy > FYLENGTH - 2) {
				sy = 1;
			}
			else if (sx > FXLENGTH - 2) {
				sx = 1;
			}
			if (display[sy][sx] == "*") {
				tailLength++;
				score += 10;
				fx = randomInt(1, FXLENGTH - 2);
				if (fx % 2 != 1) {
					fx++;
				}
				fy = randomInt(1, FYLENGTH - 2);
				display[fy][fx] = "*";
			}
			else if (gameRunning && display[sy][sx] == "o") {
				runGame = false;
			}


			if (trail.size() > tailLength) {
				cord tempC = trail.back();
				display[tempC.y][tempC.x] = " ";
				trail.pop_back();
			}
			tempSize = trail.size();
			display[sy][sx] = "0";

			Draw();
		}
	}
	return 0;
}











//#include "KeyInput.h"
//#include <vector>
//#include <iostream>
//#include <string>
//#include <time.h>
//
//
//
//using namespace std;
//
//KeyInput _KeyInput;
//
//bool runGame = true;
//
//int main()
//{
//	cout << string(16, '\n') <<
//		"_________________________________________________________________\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"_________________________________________________________________" << endl;
//	clock_t begin;
//	clock_t deltaTime = 0;
//	vector<string> test(14, " ");
//	string foo;
//	int c = 0;
//	cin >> foo;
//	while (runGame) {
//		begin = clock();
//		deltaTime += clock() - begin;
//		// Set a string vector to all spaces then in the loop change the spaces to a # sign to make lines
//		if (deltaTime > 60 && c < 14) {
//			deltaTime = 0;
//
//			test[c] = "#";
//			cout <<
//				"_________________________________________________________________\n"
//				"|                             " << test[0] << "                                 |\n"
//				"|                             " << test[1] << "                                 |\n"
//				"|                             " << test[2] << "                                 |\n"
//				"|                             " << test[3] << "                                 |\n"
//				"|                             " << test[4] << "                                 |\n"
//				"|                             " << test[5] << "                                 |\n"
//				"|                             " << test[6] << "                                 |\n"
//				"|                             " << test[7] << "                                 |\n"
//				"|                             " << test[8] << "                                 |\n"
//				"|                             " << test[9] << "                                 |\n"
//				"|                             " << test[10] << "                                 |\n"
//				"|                             " << test[11] << "                                 |\n"
//				"|                             " << test[12] << "                                 |\n"
//				"|                             " << test[13] << "                                 |\n"
//				"_________________________________________________________________" << endl;
//			c++;
//		}
//
//		/*string currKey = _KeyInput.GetKey();
//		if (currKey == "UP") {
//		cout << string(16, '\n') <<
//		"_________________________________________________________________\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"_________________________________________________________________" << endl;
//		}
//		else  {
//		cout << string(16, '\n') <<
//		"_________________________________________________________________\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                              |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"|                                                               |\n"
//		"________________________HHHHHHHHHHHHHHHHH________________________" << endl;
//		}*/
//	}
//	return 0;
//}
