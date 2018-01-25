#pragma once
#include "Animation.h"
class PlayerCharAnimation :
	public Animation {
public:
	PlayerCharAnimation();
	virtual ~PlayerCharAnimation() override;
	// Inherited via Animation
	virtual void SetSpriteObject(Game2DSprite * _spriteObject) override;
	virtual void SetDrawInfos(DrawInfo _drawInfo) override;
	virtual void DrawFrames() override;
};

