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
}


GameSoundManager::~GameSoundManager()
{
}
