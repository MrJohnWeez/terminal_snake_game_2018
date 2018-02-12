#include "KeyInput.h"
#include <conio.h>
#include "FrameUpdate.h"
#include "SnakeObject.h"
#include "Cord.h"
#include "Display.h"
#include "Fruit.h"

#include <string>

#define FXLENGTH 43 // Must be odd
#define FYLENGTH 22 // Must be even

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_R 114
#define KEY_ENTER 13

int score = 0;

using namespace std;

KeyInput _KeyInput;
FrameUpdate _FPS;
Display _Display = Display(FXLENGTH, FYLENGTH);
SnakeObject _SnakeObject = SnakeObject(FYLENGTH, FXLENGTH);
Fruit _Fruit;

bool runGame = true;
int c = 0;

int main()
{
	_Display.window[_SnakeObject.sy][_SnakeObject.sx] = "0";
	Cord currFruit = _Fruit.NewFruit(FXLENGTH, FYLENGTH);
	_Display.window[currFruit.y][currFruit.x] = "*";

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

			// Move snake in correct direction
			_SnakeObject.Step();

			if (_Display.window[_SnakeObject.sy][_SnakeObject.sx] == "*") {
				_SnakeObject.tailLength++;
				score += 10;
				Cord newFruit = _Fruit.NewFruit(FXLENGTH, FYLENGTH);
				_Display.window[newFruit.y][newFruit.x] = "*";
			}
			else if (_SnakeObject.isMoving && _Display.window[_SnakeObject.sy][_SnakeObject.sx] == "o") {
				runGame = false;
			}

			// Remove End of tail
			Cord tempC = _SnakeObject.popTrail();
			if(tempC.x != 0 && tempC.y != 0) _Display.window[tempC.y][tempC.x] = " ";

			// Set head to new location
			_Display.window[_SnakeObject.sy][_SnakeObject.sx] = "0";

			_Display.Print();
			cout << "Score: " << score;

			// Change to snake body char
			_Display.window[_SnakeObject.sy][_SnakeObject.sx] = "o";
		}
	}
	return 0;
}