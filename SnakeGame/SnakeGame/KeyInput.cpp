#include "KeyInput.h"
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_R 114
#define KEY_ENTER 13


// Return current key
string KeyInput::GetKey() {
	c = _getch();
	if (c != 224 && c != preCode) {
		preCode = c;
		switch (c) {
		case KEY_UP:
			return "UP";
			break;
		case KEY_DOWN:
			return "DOWN";
			break;
		case KEY_LEFT:
			return "LEFT";
			break;
		case KEY_RIGHT:
			return "RIGHT";
			break;
		case KEY_ESC:
			return "ESC";
			break;
		case KEY_R:
			return "R";
			break;
		}
	}
	return "";

}

void KeyInput::Reset() {
	preCode = -1;
	c = 0;
}