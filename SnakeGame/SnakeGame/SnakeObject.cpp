#include <vector>
#include <string>
#include <deque>
#include "SnakeObject.h"
#include "Cord.h"

using namespace std;

SnakeObject::SnakeObject(int in_boardY, int in_boardX) {
	ydir = 0;
	xdir = 0;
	tailLength = 0;
	boardY = in_boardY;
	boardX = in_boardX;
	sx = (in_boardX / 2);
	sy = in_boardY / 2;
	isMoving = false;
}

void SnakeObject::addTrail() {
	trail.push_front(Cord(sx, sy));
}
Cord SnakeObject::popTrail() {
	if (trail.size() > tailLength) {
		Cord tempC = trail.back();
		trail.pop_back();
		return tempC;
	}
}

void SnakeObject::Step() {
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
		sy = boardY - 2;
	}
	else if (sx < 1) {
		sx = boardX - 2;
	}
	else if (sy > boardY - 2) {
		sy = 1;
	}
	else if (sx > boardX - 2) {
		sx = 1;
	}
}

void SnakeObject::UpdateSnakeDirection(string in_string) {
	
	if (in_string == "UP") {
		ydir = 1;
		xdir = 0;
		isMoving = true;
	}
	else if (in_string == "DOWN") {
		ydir = -1;
		xdir = 0;
		isMoving = true;
	}
	else if (in_string == "LEFT") {
		ydir = 0;
		xdir = -1;
		isMoving = true;
	}
	else if (in_string == "RIGHT") {
		ydir = 0;
		xdir = 1;
		isMoving = true;
	}
}