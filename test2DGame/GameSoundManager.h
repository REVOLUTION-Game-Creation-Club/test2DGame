#pragma once
#include "al.h"
#include "alc.h"
#include "kojeomDebugLogger.h"
class GameSoundManager
{
public:
	GameSoundManager();
	~GameSoundManager();

private:
	ALCcontext* context;
	ALCdevice* device;

	ALuint buffers[];
};

