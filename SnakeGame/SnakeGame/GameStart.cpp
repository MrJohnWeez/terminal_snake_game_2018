#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 1
#define KEY_R 19

int main()
{
	int c = 0;
	while (1)
	{
		c = 0;

		switch ((c = _getch())) {
		case KEY_UP:
			cout << endl << "Up" << endl;//key up
			break;
		case KEY_DOWN:
			cout << endl << "Down" << endl;   // key down
			break;
		case KEY_LEFT:
			cout << endl << "Left" << endl;  // key left
			break;
		case KEY_RIGHT:
			cout << endl << "Right" << endl;  // key right
			break;
		}

	}

	return 0;
}