#pragma once
#include "FilePath.h"
#include "GameState.h"
#include "GameCommonSprite.h"
class MainMenuState :
	public GameState
{
public:
	MainMenuState();
	~MainMenuState() override;
	virtual void Init(IDirect3DDevice9* _d3dDevice) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	GameCommonSprite spr_bg;
	GameCommonSprite spr_foreGroundTrees;
	GameCommonSprite spr_backGroundTress;
	GameCommonSprite spr_mountainFar;
	GameCommonSprite spr_mountains;
};

