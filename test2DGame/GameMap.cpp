#include "GameMap.h"


GameMap::GameMap(const char* _tmxFileName, IDirect3DDevice9* _d3dDevice,
	char* _spriteFileName, RECT _defaultRect, unsigned int textureWidth, unsigned int textureHeight)
{
	if (_tmxFileName != nullptr) tmxParser = new TMXParser(_tmxFileName);
	else return;

	mapData = tmxParser->GetMapData();
	mapLayers = mapData->layers.size();
	// tmx map layers 갯수 만큼 map sprite 생성.
	for (int idx = 1; idx <= mapLayers; ++idx)
	{
		GameMap2DSprite* spr = new GameMap2DSprite();
		spr->Init(_d3dDevice, _spriteFileName, _defaultRect, textureWidth, textureHeight);
		tileMapSprites.push_back(spr);
	}
}


GameMap::~GameMap()
{
	if (tmxParser != nullptr) delete tmxParser;	
	for each (auto map2dSprite in tileMapSprites)
	{
		map2dSprite->~GameMap2DSprite();
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
	tileMapSprites[_layerIdx]->BeginDraw();
	int gid = 0;
	int tileIdx = 0;
	for (int y = 0; y < mapData->mapHeight; ++y)
		for (int x = 0; x < mapData->mapWidth; ++x)
		{
			gid = mapData->layers[_layerIdx].tileGIDs.at(tileIdx);
			tileMapSprites[_layerIdx]->SetSpriteRect(CalcRenderRect(gid));
			tileMapSprites[_layerIdx]->SetSpritePos(D3DXVECTOR3(x * mapData->tileWidth, y * mapData->tileHeight, 0));
			tileMapSprites[_layerIdx]->DrawSprite();
			tileIdx++;
		}
	tileMapSprites[_layerIdx]->EndDraw();
}
	

RECT GameMap::CalcRenderRect(const int _gid)
{
	RECT renderRect = { 0,0,0,0 };
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
		int leftVal = ((_gid % tileIntervalX) * mapData->tileWidth);
		int topVal = ((_gid / tileIntervalY) * mapData->tileHeight);
		renderRect.left = leftVal;
		renderRect.top = topVal;
		renderRect.right = leftVal + mapData->tileWidth;
		renderRect.bottom = topVal + mapData->tileHeight;
	}
	return renderRect;
}