#pragma once

#include "Game2DSprite.h"

//
// 96 x 128 size 의 spriteSheet로 동작합니다. ( 32*32 unit )
//

#define TILE_SIZE 42

class ChracterAnimation
{
public:
	ChracterAnimation();
	~ChracterAnimation();

	void SetSpriteObject(Game2DSprite* _spriteObject);
	void MoveForwardFrame();
	void MoveRightFrame();
	void MoveLeftFrame();
	void MoveBackwardFrame();
	
private:
	Game2DSprite* spriteObject;
	RECT renderRect;

	DWORD aniTimeEnd;
	DWORD aniTimeBegin;
	//mileseconds
	float frameTime;

	int unitX;
	int unitY;
};

