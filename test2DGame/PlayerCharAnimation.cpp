#include "PlayerCharAnimation.h"



PlayerCharAnimation::PlayerCharAnimation() {
	aniTimeBegin = GetTickCount();
}


PlayerCharAnimation::~PlayerCharAnimation() {
	// release..
}

void PlayerCharAnimation::SetSpriteObject(Game2DSprite * _spriteObject) {
	if (_spriteObject != nullptr) spriteObject = _spriteObject;
}

void PlayerCharAnimation::SetDrawInfos(FourDirDrawInfo _fourDirInfo) {
	fourDirDrawInfo = _fourDirInfo;
}

void PlayerCharAnimation::Update() {
	switch (curLookDir) {
	case LOOK_DIRECTION::forward:
		DrawFrames(fourDirDrawInfo.forwardDir);
		break;
	case LOOK_DIRECTION::back:
		DrawFrames(fourDirDrawInfo.backDir);
		break;
	case LOOK_DIRECTION::right:
		DrawFrames(fourDirDrawInfo.rightDir);
		break;
	case LOOK_DIRECTION::left:
		DrawFrames(fourDirDrawInfo.leftDir);
		break;
	}
}

void PlayerCharAnimation::DrawFrames(DrawInfo _drawInfo)
{
	aniTimeEnd = GetTickCount();
	if ((aniTimeEnd - aniTimeBegin) > _drawInfo.frameTime) {
		renderRect.left += _drawInfo.tileSize;
		if (renderRect.left >= _drawInfo.imgWidth) {
			renderRect.left = 0;
		}
		renderRect.right = renderRect.left + _drawInfo.tileSize;
		aniTimeBegin = aniTimeEnd;
	}
	//
	spriteObject->SetSpriteRect(renderRect);
}

void PlayerCharAnimation::SetLookDir(LOOK_DIRECTION _aniLook){

	if (curLookDir == _aniLook) return;

	curLookDir = _aniLook;
	DrawInfo drawInfo;
	switch (curLookDir) {
	case LOOK_DIRECTION::forward:
		drawInfo = fourDirDrawInfo.forwardDir;
		break;
	case LOOK_DIRECTION::back:
		drawInfo = fourDirDrawInfo.backDir;
		break;
	case LOOK_DIRECTION::right:
		drawInfo = fourDirDrawInfo.rightDir;
		break;
	case LOOK_DIRECTION::left:
		drawInfo = fourDirDrawInfo.leftDir;
		break;
	}
	renderRect.top = drawInfo.rectTop;
	renderRect.bottom = drawInfo.rectBottom;
	renderRect.left = drawInfo.rectLeft;
	renderRect.right = drawInfo.rectRight;
}
