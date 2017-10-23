#pragma once
#include "al.h"
#include "alc.h"
#include "WaveFile.h"
#include "kojeomDebugLogger.h"
class GameSoundManager
{
public:
	GameSoundManager();
	~GameSoundManager();

private:
	ALCcontext* context;
	ALCdevice* device;

	ALuint buffers[1];
	ALuint sources[1];
	WaveFile* gameSounds[1];
};

