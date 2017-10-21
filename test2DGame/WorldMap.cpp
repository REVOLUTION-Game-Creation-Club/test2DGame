#include "WorldMap.h"

WorldMap::WorldMap(IDirect3DDevice9* _device)
{
	device = _device;
	mapDefaultRect = { 0, 0, 0, 0 };

	gameMaps[0] = new GameMap("GameResources/test00.tmx", device,
		"GameResources/tileb.png",
		mapDefaultRect);
	gameMaps[1] = new GameMap("GameResources/test01.tmx", device,
		"GameResources/tileb.png",
		mapDefaultRect);

	gameMaps[0]->Move(0.0f, 0.0f);
	gameMaps[1]->Move(512.0f, 0.0f);
}

WorldMap::~WorldMap()
{
	for each (auto var in gameMaps)
	{
		var->~GameMap();
	}
}

void WorldMap::Update()
{
	for (int idx = 0; idx < MAX_GAME_MAP; ++idx)
	{
		gameMaps[idx]->DrawMap();
	}
}
