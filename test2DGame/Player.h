#pragma once
#include "GameObject.h"
#include "PlayerCharAnimation.h"
class Player : public GameObject
{
public:
	Player();
	~Player() override;
	virtual void Init(Game2DSprite * _spriteObject) override;
	virtual void Update() override;
	virtual D3DXVECTOR3 GetObjectPosition() override;
	virtual void Move(FLOAT _x, FLOAT _y) override;
	virtual Box2DCollider* GetAABB() override;
	virtual void SetLookDirection(LOOK_DIRECTION _lookDir) override;
private:
	PlayerCharAnimation animation;
};

