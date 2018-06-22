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

WayOut WorldMap::GetWayoutInfo(WayOutToDirection dir){
	WayOut wayoutInfo;
	auto mapType = PlayerSupervisor::GetInstance()->GetPlayerObject()->GetCurMapType();
	GameMap* curMap = gameMaps[mapType];
	for (auto wayout : curMap->GetMapData().wayoutInfo.wayouts) {
		if (GameMapUtil::DirNameToEnum(wayout.toDirection) == dir) {
			wayoutInfo = wayout;
		}
	}
	return wayoutInfo;
}
