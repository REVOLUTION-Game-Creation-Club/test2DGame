#pragma once
#include "GameMap.h"

#define MAX_GAME_MAP 2
class WorldMap
{
public:
	WorldMap(IDirect3DDevice9* _device);
	~WorldMap();
	void Update();

private:
	IDirect3DDevice9* device;
	GameMap* testGameMaps[2];
	RECT mapDefaultRect;
};

