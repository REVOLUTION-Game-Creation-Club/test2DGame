#include "GameMap.h"


GameMap::GameMap(const char* _tmxFileName, IDirect3DDevice9* _d3dDevice,
	char* _spriteFileName, RECT _defaultRect)
{
	if (_tmxFileName != nullptr) tmxFile = new TMXParser(_tmxFileName);
	else return;

	mapData = tmxFile->GetMapData();
	mapLayers = mapData->layers.size();
	// tmx map layers 갯수 만큼 map sprite 생성.
	for (int idx = 1; idx <= mapLayers; ++idx)
	{
		GameMap2DSprite* spr = new GameMap2DSprite();
		spr->Init(_d3dDevice, _spriteFileName, _defaultRect);
		tileMapSprites.push_back(spr);
	}
	
	renderRect = { 0, 0, 0, 0 };
}


GameMap::~GameMap()
{
	if (tmxFile != nullptr) delete tmxFile;	
	if (mapData != nullptr) delete mapData;
	
	vector<GameMap2DSprite*>::iterator idx = tileMapSprites.begin();
	while (idx != tileMapSprites.end())
	{
		delete (*idx);
		++idx;
	}
	tileMapSprites.clear();
}

void GameMap::Move(FLOAT _x, FLOAT _y)
{
	for (int idx = 0; idx < mapLayers; ++idx)
	{
		tileMapSprites[idx]->TranslateSprite(_x, _y);
	}
}

void GameMap::DrawMap()
{
	for (int idx = 0; idx < mapLayers; ++idx)
		DrawMapLyaers(idx);
}
// layer 별로 sprite를 만들어 각각의 내용을 그려서 중첩시킨다.
void GameMap::DrawMapLyaers(const int _layerIdx)
{
	int gid = 0;
	int tileIdx = 0;
	for (int y = 0; y < mapData->mapHeight; ++y)
		for (int x = 0; x < mapData->mapWidth; ++x)
		{
			gid = mapData->layers[_layerIdx].at(tileIdx);
			CalcRenderRect(gid);
			tileIdx++;
			tileMapSprites[_layerIdx]->SetSpriteRect(renderRect);
			tileMapSprites[_layerIdx]->SetSpritePos(D3DXVECTOR3(x * mapData->tileWidth, y * mapData->tileHeight, 0));
			tileMapSprites[_layerIdx]->DrawSprite();
		}
}
	

void GameMap::CalcRenderRect(const int _gid)
{
	int tileIntervalX = mapData->imageWidth / mapData->tileWidth;
	int tileIntervalY = mapData->imageWidth / mapData->tileHeight;
	if (_gid == 0)
	{
		renderRect.left = 0;
		renderRect.top = 0;
		renderRect.right = mapData->tileWidth;
		renderRect.bottom = mapData->tileHeight;
	}
	else
	{   
		renderRect.left = ((_gid % tileIntervalX) * mapData->tileWidth);
		renderRect.top = ((_gid / tileIntervalY) * mapData->tileHeight);
		renderRect.right = (_gid % tileIntervalX) * mapData->tileWidth + mapData->tileWidth;
		renderRect.bottom = ((_gid / tileIntervalY)) * mapData->tileHeight + mapData->tileHeight;
	}
}