#pragma once
#include "Game2DSprite.h"
#include "Box2DCollider.h"
#include "Animation.h"
#include "TMXParser.h"
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Init(Game2DSprite* _spriteObject) = 0;
	virtual void Update() = 0;
	virtual D3DXVECTOR3 GetObjectPosition() = 0;
	virtual void SetObjectPosition(FLOAT x, FLOAT y) = 0;
	virtual void SetObjectPosition(D3DXVECTOR3 vec) = 0;
	virtual void Move(FLOAT _x, FLOAT _y) = 0;
	virtual void Move(D3DXVECTOR3 vec) = 0;
	virtual Box2DCollider GetAABB() = 0;
	virtual void SetLookDirection(LOOK_DIRECTION _lookDir) = 0;
	virtual void SetPositionedMapType(TMX_MAP_TYPE curMapType) = 0;
	virtual TMX_MAP_TYPE GetCurMapType() = 0;
protected:
	Game2DSprite* spriteObject;
	Box2DCollider box2DColl;
	LOOK_DIRECTION curLookDir;
	TMX_MAP_TYPE curPositionedMapType;
};

