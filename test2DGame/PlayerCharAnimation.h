#pragma once
#include "Animation.h"
class PlayerCharAnimation :
	public Animation {
public:
	PlayerCharAnimation();
	virtual ~PlayerCharAnimation() override;
	// Inherited via Animation
	virtual void SetSpriteObject(Game2DSprite * _spriteObject) override;
	virtual void SetDrawInfos(FourDirDrawInfo _fourDirInfo) override;
	virtual void Update() override;
	virtual void SetLookDir(LOOK_DIRECTION _aniLook) override;
private:
	virtual void DrawFrames(DrawInfo _drawInfo) override;
};

