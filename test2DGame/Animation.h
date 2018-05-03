#pragma once

#include "Game2DSprite.h"

// parmeter : imgWidth, imgHeight, top, bottom, left, right, tileSize, frameTime
struct DrawInfo
{
public:
	int imgWidth;
	int imtHeight;
	int rectTop;
	int rectBottom;
	int rectLeft;
	int rectRight;
	int tileSize;
	float frameTime; // miileseconds
};

// 애니메이션의 4방향 드로우 정보를 가지고 있는 구조체.
struct FourDirDrawInfo {
public:
	DrawInfo forwardDir;
	DrawInfo backDir;
	DrawInfo rightDir;
	DrawInfo leftDir;
	FourDirDrawInfo() {}
	FourDirDrawInfo(DrawInfo _left, DrawInfo _right,
		DrawInfo _back, DrawInfo _forward) {
		forwardDir = _forward;
		leftDir = _left;
		rightDir = _right;
		backDir = _back;
	}
};

enum LOOK_DIRECTION {
	forward = 0,
	left = 1,
	right = 2,
	back = 3
};

class Animation
{
public:
	Animation();
	virtual ~Animation();
	//
	virtual void SetSpriteObject(Game2DSprite* _spriteObject) = 0;
	virtual void SetDrawInfos(FourDirDrawInfo _fourDirInfo) = 0;
	virtual void Update()= 0;
	virtual void SetLookDir(LOOK_DIRECTION _aniLook) = 0;
protected:
	LOOK_DIRECTION curLookDir;
	Game2DSprite* spriteObject;
	RECT renderRect;
	DWORD aniTimeEnd;
	DWORD aniTimeBegin;
	FourDirDrawInfo fourDirDrawInfo;
	//
	virtual void DrawFrames(DrawInfo _drawInfo) = 0;
};

