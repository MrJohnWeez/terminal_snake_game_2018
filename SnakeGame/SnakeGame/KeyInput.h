#pragma once
#include <string>

using namespace std;

#ifndef KEYINPUT_H
#define KEYINPUT_H



class KeyInput {
public:
	int preCode = -1;
	int c = 0;

	string GetKey();
	void Reset();
};

#endif