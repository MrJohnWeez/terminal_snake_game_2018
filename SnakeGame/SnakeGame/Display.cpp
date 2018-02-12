
#include <string>
#include <iostream>
#include "Display.h"


using namespace std;

void Display::Print() {
	Clear();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			cout << window[row][col];
		}
		cout << endl;
	}
}

void Display::Clear() {
	system("cls");
}

void Display::SetBoarders() {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (row == 0 || col == width - 1 || row == height - 1 || col == 0) {
				window[row][col] = "#";
			}
			else {
				window[row][col] = " ";
			}
		}
	}
}
Display::Display(int x, int y) {
	width = x;
	height = y;
	window.resize(height);
	for (int i = 0; i < height; i++) {
		window[i].resize(width);
	}
	SetBoarders();
}

