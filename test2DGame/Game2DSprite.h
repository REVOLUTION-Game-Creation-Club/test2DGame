#pragma once

#include <d3d9.h>
#include <d3dx9.h>

class Game2DSprite
{
public:
	Game2DSprite(IDirect3DDevice9* _d3dDevice, char* _spriteFileName, RECT _rect);
	~Game2DSprite();

	void DrawSprite();
	void TranslateSprite(FLOAT x, FLOAT y);
	void SetSpriteRect(RECT _spriteRect);
	void SetSpritePos(D3DXVECTOR3 _pos);

private:
	wchar_t* ConvertCharToWchar(char* str);
	char * ConvertWcharToChar(wchar_t* str);
	void CreateSprite();
	void CreateTexture2D();

	LPD3DXSPRITE spriteObject;
	LPDIRECT3DTEXTURE9 spriteTexture2D;
	IDirect3DDevice9* d3d9Device;
	char* spriteName;
	RECT spriteRect;
	D3DXVECTOR3 spritePosition;
	D3DXCOLOR spriteAlphaColor;

	D3DXMATRIX accumuMatrix;
};

