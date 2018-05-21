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
// 60fps 에서 1프레임이 소모하는 millieSecond.
#define MS_PER_FRAME 16
// ref1 : http://data-forge.blogspot.kr/2013/09/fps.html
// ref2 : http://skmagic.tistory.com/305
// ref3: http://boycoding.tistory.com/112
class GameFrameManager {
public:
	GameFrameManager() = default;
	~GameFrameManager() = default;
	void SetUpdateStatement(void(*update)(float)) {
		UpdateProcess = update;
	}
	void UpdateFrame(float deltaTime) {
		auto startTime = std::chrono::system_clock::now();
		UpdateProcess(deltaTime);
		auto lastTime = std::chrono::system_clock::now();
		auto interval = std::chrono::duration_cast<std::chrono::milliseconds>(lastTime - startTime);
		auto intervalMillisec = interval.count();
		auto delayMillieSec = MS_PER_FRAME - intervalMillisec;
		if (delayMillieSec > 0) {
			Sleep(delayMillieSec);
		}
	}
private:
	void(*UpdateProcess)(float);
};