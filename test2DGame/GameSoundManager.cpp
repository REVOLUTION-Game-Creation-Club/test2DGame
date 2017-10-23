#include "GameSoundManager.h"



GameSoundManager::GameSoundManager()
{
	// Initialization 
	device = alcOpenDevice(NULL); // select the "preferred device"
	if (device) {
		context = alcCreateContext(device, NULL);
		alcMakeContextCurrent(context);
	}

	alGenBuffers(1, buffers);

	gameSounds[0] = new WaveFile(".\\GameResources\\sounds\\test_bgm_3.wav");
	alBufferData(buffers[0], AL_FORMAT_STEREO16,
		gameSounds[0]->GetData(), gameSounds[0]->header.subChunk_2_size , 44100);
	ALenum err = alGetError();

	alGenSources(1, sources);
	err = alGetError();
	alSourcei(sources[0], AL_BUFFER, buffers[0]);
	alSourcef(sources[0], AL_GAIN, 0.2f);
	err = alGetError();
	alSourcePlay(sources[0]);
	err = alGetError();
}


GameSoundManager::~GameSoundManager()
{
	context = alcGetCurrentContext();
	device = alcGetContextsDevice(context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}
