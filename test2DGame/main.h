#pragma once
#include "resource.h"
#include <chrono>
class FPSManager {
public:
	FPSManager() {
		curFPS = 0;
		frames = 0;
		startTime = std::chrono::system_clock::now();
	}
	~FPSManager() = default;

	void CalcFPS() {
		auto lastTime = std::chrono::system_clock::now();
		auto interval = std::chrono::duration_cast<std::chrono::milliseconds>(lastTime - startTime);
		auto intervalMillisec = interval.count();
		if (intervalMillisec <= 1000) {
			frames++;
		}
		else {
			curFPS = frames;
			frames = 0; 
			startTime = std::chrono::system_clock::now();
		}
	}
	// Frames per second.
	unsigned int GetFPS() {
		return curFPS;
	}
private:
	unsigned int curFPS;
	unsigned int frames;
	std::chrono::time_point<chrono::system_clock> startTime;
};