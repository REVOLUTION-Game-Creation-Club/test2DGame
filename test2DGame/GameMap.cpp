#include "GameMap.h"


GameMap::GameMap(const char* _tmxFileName)
{
	if (_tmxFileName != nullptr) tmxFile = new TMXParser(_tmxFileName);

	mapData = tmxFile->GetMapData();
	
}


GameMap::~GameMap()
{
	delete tmxFile;
}

void GameMap::DrawMap()
{

}
