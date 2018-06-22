#pragma once
#include "GameMap.h"
#include "FilePath.h"
#define MAX_GAME_MAP 3
class WorldMap
{
public:
	WorldMap(IDirect3DDevice9* _device);
	~WorldMap();
	void Update();

private:
	IDirect3DDevice9* device;
	GameMap* gameMaps[MAX_GAME_MAP];
	RECT mapDefaultRect;
};

