#pragma once
#include <string>
#include <vector>

using namespace std;

class Display {
public:
	int width;
	int height;
	vector<vector<string>> window;
	void Print();
	void SetBoarders();
	Display(int x, int y);
};