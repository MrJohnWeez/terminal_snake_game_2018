#pragma once
#include <string>
#include <time.h>

using namespace std;

class FrameUpdate {
public:
	bool clockReady;
	clock_t begin;
	clock_t deltaTime;
	void Start();
	bool Ready(float frequency);
	FrameUpdate();
};