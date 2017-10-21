#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	void Update() override;
	void SetSpriteObject(Game2DSprite* _spriteObject) override;
	D3DXVECTOR3 GetObjectPostion() override;
	void Move(FLOAT _x, FLOAT _y) override;
};

