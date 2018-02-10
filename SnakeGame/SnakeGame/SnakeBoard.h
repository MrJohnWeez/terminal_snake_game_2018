#pragma once
#include <vector>
#include <string>

using namespace std;
#ifndef SNAKEBOARD_H
#define SNAKEBOARD_H

class SnakeBoard {
public:
	int boardHeight;
	int boardWidth;

	string board[20][20];
	void printBoard();
	SnakeBoard();


};
#endif