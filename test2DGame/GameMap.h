#pragma once
#include "Game2DSprite.h"
#include "TMXParser.h"

//
// based 2d tile map
// 
class GameMap
{
public:
	GameMap(const char* _tmxFileName, IDirect3DDevice9* _d3dDevice,
			char* _spriteFileName, RECT _rect);
	~GameMap();

	void DrawMap();

private:
	MapData* mapData;
	TMXParser* tmxFile;
	Game2DSprite* spriteObject;
	RECT renderRect;

	void CalcRenderRect(int _gid);
};

