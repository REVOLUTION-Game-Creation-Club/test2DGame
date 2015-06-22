#include "GameMap.h"


GameMap::GameMap(const char* _tmxFileName, IDirect3DDevice9* _d3dDevice,
	char* _spriteFileName, RECT _defaultRect)
{
	if (_tmxFileName != nullptr) tmxFile = new TMXParser(_tmxFileName);
	else return;

	mapData = tmxFile->GetMapData();
	mapLayers = mapData->vec_layers.size();
	// tmx map layers 갯수 만큼 map sprite 생성.
	for (int idx = 1; idx <= mapLayers; ++idx)
	{
		vec_tileMapSprites.push_back(new Game2DSprite(_d3dDevice, _spriteFileName, _defaultRect));
	}
	
	renderRect = { 0, 0, 0, 0 };
}


GameMap::~GameMap()
{
	delete tmxFile;
}


void GameMap::DrawMap()
{
	for (int idx = 0; idx < mapLayers; ++idx)
		DrawMapLyaers(idx);
}
// layer 별로 sprite를 만들어 각각의 내용을 그려서 중첩시킨다.
void GameMap::DrawMapLyaers(const int layerIdx)
{
	vec_tileMapSprites[layerIdx]->BeginSpriteForMAP();

	int gid = 0;
	int tileIdx = 0;
	for (int y = 0; y < mapData->mapHeight; ++y)
		for (int x = 0; x < mapData->mapWidth; ++x)
		{

			gid = mapData->vec_layers[layerIdx].at(tileIdx);
			CalcRenderRect(gid);
			tileIdx++;

			vec_tileMapSprites[layerIdx]->SetSpriteRect(renderRect);
			vec_tileMapSprites[layerIdx]->SetSpritePos(D3DXVECTOR3(x * mapData->tileWidth, y * mapData->tileHeight, 0));
			vec_tileMapSprites[layerIdx]->DrawSpriteForMAP();

		}

	vec_tileMapSprites[layerIdx]->EndSpriteForMAP();
}

void GameMap::CalcRenderRect(const int _gid)
{
	int tileInterval = mapData->imageWidth / mapData->tileWidth;
	if (_gid == 0)
	{
		renderRect.left = 0;
		renderRect.top = 0;
		renderRect.right = mapData->tileWidth;
		renderRect.bottom = mapData->tileHeight;
	}
	else
	{   
		renderRect.left = ((_gid % tileInterval) * mapData->tileWidth);
		renderRect.top = ((_gid / tileInterval) * mapData->tileHeight);
		renderRect.right = (_gid % tileInterval) * mapData->tileWidth + mapData->tileWidth;
		renderRect.bottom = ((_gid / tileInterval) ) * mapData->tileHeight + mapData->tileHeight;
	}
}