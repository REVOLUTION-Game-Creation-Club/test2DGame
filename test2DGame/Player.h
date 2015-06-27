#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	virtual void Draw();
	virtual void Update();
	virtual void SetSpriteObject(Game2DSprite* _spriteObject);

private:
	Game2DSprite* spriteObject;
};

