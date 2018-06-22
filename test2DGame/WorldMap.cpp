#include "WorldMap.h"

WorldMap::WorldMap(IDirect3DDevice9* _device){
	device = _device;
	mapDefaultRect = { 0, 0, 0, 0 };

	gameMaps[0] = new GameMap(TMX_MAP_TYPE::MAIN_TOWN, device,
		FilePath::GetInstance()->tileMapSprite,
		mapDefaultRect, 512, 512 );
	gameMaps[1] = new GameMap(TMX_MAP_TYPE::TOWN_0, device, 
		FilePath::GetInstance()->tileMapSprite,
		mapDefaultRect, 512, 512);
	gameMaps[2] = new GameMap(TMX_MAP_TYPE::TOWN_1, device,
		FilePath::GetInstance()->tileMapSprite,
		mapDefaultRect, 512, 512);
}

WorldMap::~WorldMap(){
	for each (auto var in gameMaps){
		var->~GameMap();
	}
}

void WorldMap::Update(){
	auto mapType = PlayerSupervisor::GetInstance()->GetPlayerObject()->GetCurMapType();
	gameMaps[mapType]->DrawMap();
}
