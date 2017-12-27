#pragma once
#include "GameMap2DSprite.h"
#include "TMXParser.h"
#include <vector>

using namespace std;

//
// based 2d tile map
// 
class GameMap
{
public:
	GameMap(TMX_MAP_TYPE mapType, IDirect3DDevice9* _d3dDevice, char* _spriteFileName, RECT _defaultRect, unsigned int textureWidth, unsigned int textureHeight);
	~GameMap();

	void DrawMap();
	void Move(FLOAT _x, FLOAT _y);
private:
	MapData mapData;
	vector<GameMap2DSprite*> tileMapSprites;
	int mapLayerCnt;

	void DrawMapLyaers(const int _layerIdx);
	RECT CalcRenderRect(const int _gid);
};

