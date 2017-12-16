#include "MainMenuState.h"



MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init(IDirect3DDevice9* _d3dDevice)
{
	spr_bg.Init(_d3dDevice, "", RECT{});
	spr_foreGroundTrees.Init(_d3dDevice, "", RECT{});
	spr_backGroundTress.Init(_d3dDevice, "", RECT{});
	spr_mountainFar.Init(_d3dDevice, "", RECT{});
	spr_mountains.Init(_d3dDevice, "", RECT{});
}

void MainMenuState::Update()
{
	spr_bg.DrawSprite();
}

void MainMenuState::Release()
{
}
