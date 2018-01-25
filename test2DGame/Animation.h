#pragma once

#include "Game2DSprite.h"

// parmeter : imgWidth, imgHeight, top, bottom, left, right, tileSize, frameTime
struct DrawInfo
{
	int imgWidth;
	int imtHeight;
	int rectTop;
	int rectBottom;
	int rectLeft;
	int rectRight;
	int tileSize;
	float frameTime; // miileseconds
};

enum CHARACTER_LOOK_ANIMATION {
	FRONT = 0,
	LEFT = 1,
	RIGHT = 2,
	BACK = 3
};

class Animation
{
public:
	Animation();
	virtual ~Animation();

	virtual void SetSpriteObject(Game2DSprite* _spriteObject) = 0;
	virtual void SetDrawInfos(DrawInfo _drawInfo) = 0;
	virtual void DrawFrames()= 0;
	
protected:
	Game2DSprite* spriteObject;
	RECT renderRect;

	DWORD aniTimeEnd;
	DWORD aniTimeBegin;

	DrawInfo aniDrawInfo;
};

