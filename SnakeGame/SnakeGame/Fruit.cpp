#include "Fruit.h"
#include "Cord.h"
#include <random>

using namespace std;


Fruit::Fruit() {

}
Cord Fruit::NewFruit(int board_width, int board_height){
	fx = RandomInt(1, board_width - 2);
	if (fx % 2 != 1) {
		fx++;
	}
	fy = RandomInt(1, board_height - 2);
	return Cord(fx, fy);
}
int Fruit::RandomInt(int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;
}