#include "CharacterAnimation.h"


CharacterAnimation::CharacterAnimation()
{
	frameTime = 200.0f;
	renderRect = { 0, 0, 0, 32 };
	unitX = 96;
	unitY = 128;
	aniTimeBegin = GetTickCount();
}


CharacterAnimation::~CharacterAnimation()
{
	if (spriteObject != nullptr) delete spriteObject;
}

void CharacterAnimation::SetSpriteObject(Game2DSprite* _spriteObject)
{
	if (_spriteObject != nullptr) spriteObject = _spriteObject;
}

void CharacterAnimation::MoveForwardFrame()
{
	aniTimeEnd = GetTickCount();
	renderRect.top = 0;
	renderRect.bottom = 32;

	if ((aniTimeEnd - aniTimeBegin) > frameTime)
	{
		renderRect.left += TILE_SIZE;

		if (renderRect.left >= unitX)
			renderRect.left = 0;

		renderRect.right = renderRect.left + TILE_SIZE;
		aniTimeBegin = aniTimeEnd;
	}

	spriteObject->SetSpriteRect(renderRect);
}

void CharacterAnimation::MoveBackwardFrame()
{
	aniTimeEnd = GetTickCount();
	renderRect.top = 96;
	renderRect.bottom = 128;

	if ((aniTimeEnd - aniTimeBegin) > frameTime)
	{
		renderRect.left += TILE_SIZE;
		

		if (renderRect.left >= unitX)
			renderRect.left = 0;

		renderRect.right = renderRect.left + TILE_SIZE;
		aniTimeBegin = aniTimeEnd;
	}

	spriteObject->SetSpriteRect(renderRect);
}

void CharacterAnimation::MoveLeftFrame()
{
	aniTimeEnd = GetTickCount();
	renderRect.top = 32;
	renderRect.bottom = 64;

	if ((aniTimeEnd - aniTimeBegin) > frameTime)
	{
		renderRect.left += TILE_SIZE;
		

		if (renderRect.left >= unitX)
			renderRect.left = 0;

		renderRect.right = renderRect.left + TILE_SIZE;
		aniTimeBegin = aniTimeEnd;
	}

	spriteObject->SetSpriteRect(renderRect);
}

void CharacterAnimation::MoveRightFrame()
{
	aniTimeEnd = GetTickCount();
	renderRect.top = 64;
	renderRect.bottom = 96;

	if ((aniTimeEnd - aniTimeBegin) > frameTime)
	{
		renderRect.left += TILE_SIZE;
		

		if (renderRect.left >= unitX)
			renderRect.left = 0;

		renderRect.right = renderRect.left + TILE_SIZE;
		aniTimeBegin = aniTimeEnd;
	}

	spriteObject->SetSpriteRect(renderRect);
}
