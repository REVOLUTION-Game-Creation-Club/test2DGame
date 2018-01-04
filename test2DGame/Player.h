#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	~Player() override;

	virtual void Update() override;
	virtual void SetSpriteObject(Game2DSprite* _spriteObject) override;
	virtual D3DXVECTOR3 GetObjectPosition() override;
	virtual void Move(FLOAT _x, FLOAT _y) override;
	virtual Box2DCollider* GetAABB() override;
private:
};

