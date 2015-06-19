#pragma once
#include "Game2DSprite.h"
#include "TMXParser.h"
class GameMap
{
public:
	GameMap(const char* _tmxFileName);
	~GameMap();

	void DrawMap();

private:
	MapData* mapData;
	TMXParser* tmxFile;
};

