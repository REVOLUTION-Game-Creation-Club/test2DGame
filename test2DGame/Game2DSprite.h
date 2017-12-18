#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "kojeomDebugLogger.h"
#include "StringUtil.h"
#define DEGREE_TO_RADIAN 0.01745329251f

// ref # 1: https://msdn.microsoft.com/ko-kr/library/windows/desktop/bb174249(v=vs.85).aspx
class Game2DSprite{
public:
	Game2DSprite();
	virtual ~Game2DSprite();

	virtual void Init(IDirect3DDevice9* _d3dDevice,
		char* _spriteFileName, RECT _rect, unsigned int textureWidth, unsigned int textureHeight) = 0;
	virtual void DrawSprite() = 0;
	virtual void TranslateSprite(FLOAT _x, FLOAT _y) = 0;
	virtual void SetSpriteRect(RECT _spriteRect) = 0;
	virtual RECT GetSpriteRect() = 0;
	virtual void SetSpritePos(D3DXVECTOR3 _pos) = 0;
	virtual D3DXVECTOR3 GetSpritePos() = 0;

protected:
	virtual void CreateSprite() = 0;
	virtual void CreateTexture2D() = 0;

	LPD3DXSPRITE spriteObject;
	LPDIRECT3DTEXTURE9 spriteTexture2D;
	IDirect3DDevice9* d3d9Device;
	char* spriteName;
	RECT spriteRect;
	D3DXVECTOR3 spritePosition;
	D3DXVECTOR3 spriteCenterPos;
	D3DXCOLOR spriteAlphaColor;
	D3DXMATRIX transMatrix;
	
	unsigned int texturePixelWidth;
	unsigned int texturePixelHeight;
};

