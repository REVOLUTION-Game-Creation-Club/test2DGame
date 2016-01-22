#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#define DEGREE_TO_RADIAN 0.01745329251f

class Game2DSprite
{
public:
	Game2DSprite(IDirect3DDevice9* _d3dDevice, char* _spriteFileName, RECT _rect);
	~Game2DSprite();

	void DrawSprite();
	void DrawSpriteForMAP();
	void BeginSpriteForMAP();
	void EndSpriteForMAP();
	void TranslateSprite(FLOAT _x, FLOAT _y);
	void SetSpriteRect(RECT _spriteRect);
	void SetSpritePos(D3DXVECTOR3 _pos);
	D3DXVECTOR3 GetSpritePos();

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
	D3DXVECTOR3 spriteCenterPos;
	D3DXCOLOR spriteAlphaColor;
	D3DXMATRIX transMatrix;
};

