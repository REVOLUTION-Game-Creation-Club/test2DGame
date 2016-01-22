#include "WorldMap.h"

WorldMap::WorldMap(IDirect3DDevice9* _device)
{
	device = _device;
	mapDefaultRect = { 0, 0, 0, 0 };

	testGameMaps[0] = new GameMap("GameResources/test00.tmx", device,
		"GameResources/tileb.png",
		mapDefaultRect);
	testGameMaps[1] = new GameMap("GameResources/test01.tmx", device,
		"GameResources/tileb.png",
		mapDefaultRect);

	testGameMaps[0]->Move(0.0f, 0.0f);
	testGameMaps[1]->Move(512.0f, 0.0f);
}

WorldMap::~WorldMap()
{
	delete[] testGameMaps;
}

void WorldMap::Update()
{
	for (int idx = 0; idx < MAX_GAME_MAP; ++idx)
	{
		testGameMaps[idx]->DrawMap();
	}
	
}
