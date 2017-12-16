#include "WorldMap.h"

WorldMap::WorldMap(IDirect3DDevice9* _device)
{
	device = _device;
	mapDefaultRect = { 0, 0, 0, 0 };

	gameMaps[0] = new GameMap(FilePath::GetInstance()->tmxFile_0, device,
		FilePath::GetInstance()->tileMap,
		mapDefaultRect);
	gameMaps[1] = new GameMap(FilePath::GetInstance()->tmxFile_1, device,
		FilePath::GetInstance()->tileMap,
		mapDefaultRect);
	// 1번 맵과 2번맵의 offset 값 512 적용
	// 이 값은 테스트용..
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
