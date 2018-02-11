#include "KeyInput.h"
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <deque>
#include "FrameUpdate.h"
#include "SnakeObject.h"
#include "Cord.h"

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

int score = 0;
int fx;
int fy;

using namespace std;

string display[FYLENGTH][FXLENGTH];

KeyInput _KeyInput;
SnakeObject _SnakeObject = SnakeObject(FYLENGTH, FXLENGTH);

bool runGame = true;
bool gameRunning = false;

string currKey = "";
int c = 0;
FrameUpdate _FPS;


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
	display[_SnakeObject.sy][_SnakeObject.sx] = "0";
	fx = randomInt(1, FXLENGTH - 2);
	if (fx % 2 != 1) {
		fx++;
	}
	fy = randomInt(1, FYLENGTH - 2);
	display[fy][fx] = "*";


	
	while (runGame) {
		// Start frame
		_FPS.Start();

		// Get keyboard input
		string c = _KeyInput.GetKey();
		if (c == "ESC") runGame = false;

		// Update snake's moving direction
		_SnakeObject.UpdateSnakeDirection(c);
		
		if (_FPS.Ready(60)) {
			
			_SnakeObject.addTrail();
			_SnakeObject.Step();

			if (display[_SnakeObject.sy][_SnakeObject.sx] == "*") {
				_SnakeObject.tailLength++;
				score += 10;
				fx = randomInt(1, FXLENGTH - 2);
				if (fx % 2 != 1) {
					fx++;
				}
				fy = randomInt(1, FYLENGTH - 2);
				display[fy][fx] = "*";
			}
			else if (_SnakeObject.isMoving && display[_SnakeObject.sy][_SnakeObject.sx] == "o") {
				runGame = false;
			}

			// Remove End of tail
			Cord tempC = _SnakeObject.popTrail();
			display[tempC.y][tempC.x] = " ";

			// Set head to new location
			display[_SnakeObject.sy][_SnakeObject.sx] = "0";

			Draw();

			// Change to snake body char
			display[_SnakeObject.sy][_SnakeObject.sx] = "o";
		}
	}
	return 0;
}