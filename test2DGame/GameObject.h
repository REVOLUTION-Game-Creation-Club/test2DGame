#pragma once
#include "Game2DSprite.h"
#include "Box2DCollider.h"
#include "Animation.h"
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Init(Game2DSprite* _spriteObject) = 0;
	virtual void Update() = 0;
	virtual D3DXVECTOR3 GetObjectPosition() = 0;
	virtual void Move(FLOAT _x, FLOAT _y) = 0;
	virtual Box2DCollider* GetAABB() = 0;
	virtual void SetLookDirection(LOOK_DIRECTION _lookDir) = 0;
protected:
	Game2DSprite* spriteObject;
	Box2DCollider box2DColl;
	LOOK_DIRECTION curLookDir;
};

