#include "GameSoundManager.h"

GameSoundManager* GameSoundManager::instance = nullptr;

GameSoundManager::GameSoundManager()
{
	// 전체적인 흐름은 다음과 같다.
	// 1. device 생성 -> context 생성
	// 2. Buffer를 생성. ( 사운드 갯수만큼)
	// -> Buffer는 실제 사운드 Raw Data를 담는 메모리공간.
	// 3. Source는 실제 OpenAL에서 사용되는 음악사운드 오브젝트이다.
	// -> 이 Source는 Buffer와 1:1로 매칭된다고 보면 된다.
	// 4. alSorucei와 같은 메소드를 이용해 source와 buffer간에 1:1로 원소를 매칭.

	// Initialization 
	device = alcOpenDevice(NULL); // select the "preferred device"
	if (device) {
		context = alcCreateContext(device, NULL);
		alcMakeContextCurrent(context);
	}
	// 버퍼 메모리 공간 생성.
	alGenBuffers(SOUND_TOTAL_NUM, buffers);
	// WaveFile 로딩.
	gameSounds[0] = new WaveFile(".\\GameResources\\sounds\\test_bgm_2.wav");
	alBufferData(buffers[0], AL_FORMAT_STEREO16,
		gameSounds[0]->GetData(), gameSounds[0]->header.subChunk_2_size ,
		44100);
	// Sources 메모리 공간 생성.
	alGenSources(SOUND_TOTAL_NUM, sources);
	// soruce와 buffer의 각 원소를 1:1로 매칭.
	alSourcei(sources[0], AL_BUFFER, buffers[0]);
}
GameSoundManager * GameSoundManager::GetInstance()
{
	if (instance == nullptr) instance = new GameSoundManager();
	return instance;
}
GameSoundManager::~GameSoundManager()
{
	context = alcGetCurrentContext();
	device = alcGetContextsDevice(context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

void GameSoundManager::PlayGameSound(GAME_SOUND_TYPE type, const float volume)
{
	alSourcef(sources[type], AL_GAIN, 0.1f);
	alSourcePlay(sources[type]);
}
void GameSoundManager::StopGameSound(GAME_SOUND_TYPE type)
{
	alSourceStop(sources[type]);
}