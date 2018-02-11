#pragma once
#include <string>

using namespace std;

#ifndef KEYINPUT_H
#define KEYINPUT_H



class KeyInput {
public:
	int c = -1;
	string GetKey();
};

#endif