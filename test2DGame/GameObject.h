#pragma once
#include "Game2DSprite.h"
#include "Box2DCollider.h"
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update() = 0;
	virtual void SetSpriteObject(Game2DSprite* _spriteObject) = 0;
	virtual D3DXVECTOR3 GetObjectPosition() = 0;
	virtual void Move(FLOAT _x, FLOAT _y) = 0;
	virtual Box2DCollider* GetAABB() = 0;
protected:
	Game2DSprite* spriteObject;
	Box2DCollider box2DColl;
};

