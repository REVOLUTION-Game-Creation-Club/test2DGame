#include "GameMap.h"


GameMap::GameMap(const char* _tmxFileName, IDirect3DDevice9* _d3dDevice,
				 char* _spriteFileName, RECT _rect)
{
	if (_tmxFileName != nullptr) tmxFile = new TMXParser(_tmxFileName);
	else return;

	mapData = tmxFile->GetMapData();
	spriteObject = new Game2DSprite(_d3dDevice, _spriteFileName, _rect);
	renderRect = { 0, 0, 0, 0 };
}


GameMap::~GameMap()
{
	delete tmxFile;
}

// 0번째 레이어에 대한 내용을 그리는걸로 test 중.
void GameMap::DrawMap()
{
	spriteObject->BeginSpriteForMAP();

	int gid = 0;
	int tileIdx = 0;
	for (int y = 0; y < mapData->mapHeight; y++)
		for (int x = 0; x < mapData->mapWidth; x++)
		{
			gid = mapData->vec_layers[0].at(tileIdx);
			tileIdx++;
			CalcRenderRect(gid);

			spriteObject->SetSpriteRect(renderRect);
			spriteObject->SetSpritePos(D3DXVECTOR3(x * mapData->tileWidth, y * mapData->tileHeight , 0));
			spriteObject->DrawSpriteForMAP();
		}

	spriteObject->EndSpriteForMAP();
}

void GameMap::CalcRenderRect(int _gid)
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