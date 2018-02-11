#include <string>
#include <time.h>
#include "FrameUpdate.h"

using namespace std;

FrameUpdate::FrameUpdate() {
	begin = 0;
	deltaTime = 0;
	clockReady = false;
}

void FrameUpdate::Start() {
	begin = clock();
}

bool FrameUpdate::Ready(float frequency) {
	deltaTime += clock() - begin;
	if (deltaTime > frequency) {
		deltaTime = 0;
		return true;
	}
	else {
		return false;
	}
}

