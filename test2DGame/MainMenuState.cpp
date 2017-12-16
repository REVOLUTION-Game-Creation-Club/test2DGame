#include "MainMenuState.h"



MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init(IDirect3DDevice9* _d3dDevice)
{
	spr_bg.Init(_d3dDevice, FilePath::GetInstance()->mainmenu_bg, RECT{});
	spr_foreGroundTrees.Init(_d3dDevice, FilePath::GetInstance()->mainmenu_foregroundTrees, RECT{});
	spr_backGroundTress.Init(_d3dDevice, FilePath::GetInstance()->mainmenu_backgroundTrees, RECT{});
	spr_mountainFar.Init(_d3dDevice, FilePath::GetInstance()->mainmenu_mountainFar, RECT{});
	spr_mountains.Init(_d3dDevice, FilePath::GetInstance()->mainmenu_mountains, RECT{});
}

void MainMenuState::Update()
{
	spr_bg.DrawSprite();
	spr_mountainFar.DrawSprite();
	spr_backGroundTress.DrawSprite();
	spr_foreGroundTrees.DrawSprite();
	spr_mountains.DrawSprite();
}

void MainMenuState::Release()
{
	// to do
}
