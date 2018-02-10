#include "SnakeBoard.h"
#include <vector>
#include <iostream>
#include <string>


using namespace std;

void SnakeBoard::printBoard() {

}
SnakeBoard::SnakeBoard() {
	boardHeight = 20;
	boardWidth = 20;
	for (int r = 0; r < boardHeight; r++) {
		for (int c = 0; c < boardWidth; c++) {
			board[r][c] = " ";
		}
	}
}