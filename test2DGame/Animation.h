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

class Animation
{
public:
	Animation();
	~Animation();

	void SetSpriteObject(Game2DSprite* _spriteObject);
	void SetDrawInfos(DrawInfo _drawInfo);
	void DrawFrames();
	
private:
	Game2DSprite* spriteObject;
	RECT renderRect;

	DWORD aniTimeEnd;
	DWORD aniTimeBegin;

	DrawInfo aniDrawInfo;
};

