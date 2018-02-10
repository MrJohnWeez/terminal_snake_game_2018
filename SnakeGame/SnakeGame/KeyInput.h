#pragma once
#include <string>

using namespace std;

class KeyInput {
public:
	int preCode = -1;
	int c = 0;

	string GetKey();
	void Reset();
};