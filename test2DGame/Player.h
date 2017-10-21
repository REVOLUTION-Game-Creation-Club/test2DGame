#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void SetSpriteObject(Game2DSprite* _spriteObject) override;
	virtual D3DXVECTOR3 GetObjectPostion() override;
	virtual void Move(FLOAT _x, FLOAT _y) override;
};

