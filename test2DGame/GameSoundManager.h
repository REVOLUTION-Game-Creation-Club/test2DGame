#pragma once
#include "al.h"
#include "alc.h"
#include "WaveFile.h"
#include "kojeomDebugLogger.h"

#define SOUND_TOTAL_NUM 1
enum GAME_SOUND_TYPE
{
	BGM_MAIN = 0,
	BGM_LOBBY = 1
};

class GameSoundManager
{
public:
	static GameSoundManager* GetInstance();
	~GameSoundManager();

	void PlayGameSound(GAME_SOUND_TYPE type, const float volume);
	void StopGameSound(GAME_SOUND_TYPE type);
private:
	ALCcontext* context = nullptr;
	ALCdevice* device = nullptr;

	ALuint buffers[SOUND_TOTAL_NUM];
	ALuint sources[SOUND_TOTAL_NUM];
	WaveFile* gameSounds[SOUND_TOTAL_NUM];
	GameSoundManager();
	static GameSoundManager* instance;
};

