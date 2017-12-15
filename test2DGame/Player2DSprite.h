#pragma once
#include "Game2DSprite.h"
class Player2DSprite :
	public Game2DSprite
{
public:
	Player2DSprite();
	~Player2DSprite() override;
	virtual void Init(IDirect3DDevice9 * _d3dDevice, char * _spriteFileName, RECT _rect) override;
	virtual void DrawSprite() override;
	virtual void TranslateSprite(FLOAT _x, FLOAT _y) override;
	virtual void SetSpriteRect(RECT _spriteRect) override;
	virtual void SetSpritePos(D3DXVECTOR3 _pos) override;
	virtual RECT GetSpriteRect() override;
	virtual D3DXVECTOR3 GetSpritePos() override;
protected:
	virtual void CreateSprite() override;
	virtual void CreateTexture2D() override;
};

