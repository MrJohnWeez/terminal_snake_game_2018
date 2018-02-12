#pragma once

using namespace std;
#include "Cord.h"

using namespace std;

class Fruit {
public:
	int fx;
	int fy;
	Fruit();
	Cord NewFruit(int min, int max);
	int RandomInt(int min, int max);
};