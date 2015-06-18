#pragma once
#include "Game2DSprite.h"

class GameMap
{
public:
	GameMap(const char* _tmxFileName);
	~GameMap();

	void DrawMap();

private:
	unsigned int mapWidth;
	unsigned int mapHeight;
	unsigned int tileWidth;
	unsigned int tileHeight;
};

