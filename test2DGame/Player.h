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
	virtual void SetObjectPosition(FLOAT x, FLOAT y) override;
	virtual void Move(FLOAT _x, FLOAT _y) override;
	virtual void SetObjectPosition(D3DXVECTOR3 vec) override;
	virtual void Move(D3DXVECTOR3 vec) override;
	virtual Box2DCollider GetAABB() override;
	virtual void SetLookDirection(LOOK_DIRECTION _lookDir) override;
	virtual void SetPositionedMapType(TMX_MAP_TYPE curMapType) override;
	virtual TMX_MAP_TYPE GetCurMapType() override;
private:
	PlayerCharAnimation animation;
	virtual void UpdateAABB() override;
};

