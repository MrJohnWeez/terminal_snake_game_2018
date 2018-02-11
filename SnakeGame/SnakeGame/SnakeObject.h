#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <deque>
#include "Cord.h"

using namespace std;



class SnakeObject {
public:
	void UpdateSnakeDirection(string in_string);
	bool isMoving;
	deque<Cord> trail;
	void addTrail();
	Cord popTrail();
	SnakeObject(int boardY, int boardX);
	void Step();
	int ydir;
	int xdir;
	int tailLength;
	int sx;
	int sy;
	int boardY;
	int boardX;
};