#pragma once
#include "Game2DSprite.h"
class GameMap2DSprite :
	public Game2DSprite
{
public:
	GameMap2DSprite();
	~GameMap2DSprite() override;

	virtual void Init(IDirect3DDevice9* _d3dDevice, char* _spriteFileName, RECT _rect, unsigned int textureWidth, unsigned int textureHeight);
	virtual void DrawSprite() override;
	virtual void BeginDraw();
	virtual void EndDraw();
	virtual void TranslateSprite(FLOAT _x, FLOAT _y) override;
	virtual void SetSpriteRect(RECT _spriteRect) override;
	virtual void SetSpritePos(D3DXVECTOR3 _pos) override;
	virtual RECT GetSpriteRect() override;
	virtual D3DXVECTOR3 GetSpritePos() override;
protected:
	virtual void CreateSprite() override;
	virtual void CreateTexture2D() override;

};

