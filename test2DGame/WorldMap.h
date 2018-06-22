#pragma once
#include "GameMap.h"
#include "FilePath.h"
#include "PlayerSupervisor.h"
#include "GameMapUtil.h"
#include "Simple2DCamera.h"
class WorldMap
{
public:
	WorldMap(IDirect3DDevice9* _device);
	~WorldMap();
	void Update();
	WayOut GetWayoutInfo(WayOutToDirection dir);
private:
	IDirect3DDevice9* device;
	GameMap* gameMaps[TMX_MAP_TYPE::MAP_TOTAL_NUM];
	RECT mapDefaultRect;
};

