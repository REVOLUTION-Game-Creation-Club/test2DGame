#pragma once
#include "Game2DSprite.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Draw() = 0 ;
	virtual void Update() = 0;
	virtual void SetSpriteObject(Game2DSprite* _spriteObject) = 0;
};

