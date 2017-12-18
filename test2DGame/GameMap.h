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
	GameMap(const char* _tmxFileName, IDirect3DDevice9* _d3dDevice,
			char* _spriteFileName, RECT _defaultRect, unsigned int textureWidth, unsigned int textureHeight);
	~GameMap();

	void DrawMap();
	void Move(FLOAT _x, FLOAT _y);
private:
	MapData* mapData;
	TMXParser* tmxParser;
	vector<GameMap2DSprite*> tileMapSprites;
	int mapLayers;

	void DrawMapLyaers(const int _layerIdx);
	RECT CalcRenderRect(const int _gid);
};

