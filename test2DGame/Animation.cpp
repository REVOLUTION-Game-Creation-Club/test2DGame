#include "Animation.h"


Animation::Animation()
{
	aniTimeBegin = GetTickCount();
}


Animation::~Animation()
{
	//if (spriteObject != nullptr) delete spriteObject;
}

void Animation::SetSpriteObject(Game2DSprite* _spriteObject)
{
	if (_spriteObject != nullptr) spriteObject = _spriteObject;
}

void Animation::SetDrawInfos(DrawInfo _drawInfo)
{
	aniDrawInfo = _drawInfo;

	renderRect.top = aniDrawInfo.rectTop;
	renderRect.bottom = aniDrawInfo.rectBottom;
	renderRect.left = aniDrawInfo.rectLeft;
	renderRect.right = aniDrawInfo.rectRight;
}

void Animation::DrawFrames()
{
	aniTimeEnd = GetTickCount();

	if ((aniTimeEnd - aniTimeBegin) > aniDrawInfo.frameTime)
	{
		renderRect.left += aniDrawInfo.tileSize;

		if (renderRect.left >= aniDrawInfo.imgWidth)
			renderRect.left = 0;

		renderRect.right = renderRect.left + aniDrawInfo.tileSize;
		aniTimeBegin = aniTimeEnd;
	}

	spriteObject->SetSpriteRect(renderRect);
}
