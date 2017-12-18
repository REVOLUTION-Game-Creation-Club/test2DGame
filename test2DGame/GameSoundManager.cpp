#include "GameSoundManager.h"

GameSoundManager* GameSoundManager::instance = nullptr;

GameSoundManager::GameSoundManager()
{
	// ��ü���� �帧�� ������ ����.
	// 1. device ���� -> context ����
	// 2. Buffer�� ����. ( ���� ������ŭ)
	// -> Buffer�� ���� ���� Raw Data�� ��� �޸𸮰���.
	// 3. Source�� ���� OpenAL���� ���Ǵ� ���ǻ��� ������Ʈ�̴�.
	// -> �� Source�� Buffer�� 1:1�� ��Ī�ȴٰ� ���� �ȴ�.
	// 4. alSorucei�� ���� �޼ҵ带 �̿��� source�� buffer���� 1:1�� ���Ҹ� ��Ī.

	// Initialization 
	device = alcOpenDevice(NULL); // select the "preferred device"
	if (device) {
		context = alcCreateContext(device, NULL);
		alcMakeContextCurrent(context);
	}
	// ���� �޸� ���� ����.
	alGenBuffers(SOUND_TOTAL_NUM, buffers);
	// WaveFile �ε�.
	gameSounds[0] = new WaveFile(".\\GameResources\\sounds\\test_bgm_2.wav");
	alBufferData(buffers[0], AL_FORMAT_STEREO16,
		gameSounds[0]->GetData(), gameSounds[0]->header.subChunk_2_size ,
		44100);
	// Sources �޸� ���� ����.
	alGenSources(SOUND_TOTAL_NUM, sources);
	// soruce�� buffer�� �� ���Ҹ� 1:1�� ��Ī.
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