#include "MainMenuState.h"



MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init(IDirect3DDevice9* _d3dDevice)
{
	spr_bg.Init(_d3dDevice, FilePath::GetInstance()->mainmenu_bg,
		RECT{0, 0, 1360, 800}, 1360, 800);
	spr_foreGroundTrees.Init(_d3dDevice,
		FilePath::GetInstance()->mainmenu_foregroundTrees,
		RECT{0, 0, 2720, 800}, 2720, 800);
	spr_backGroundTress.Init(_d3dDevice,
		FilePath::GetInstance()->mainmenu_backgroundTrees,
		RECT{0, 0, 2720, 800}, 2720, 800);
	spr_mountainFar.Init(_d3dDevice,
		FilePath::GetInstance()->mainmenu_mountainFar,
		RECT{0, 0, 1360, 800}, 1360, 800);
	spr_mountains.Init(_d3dDevice,
		FilePath::GetInstance()->mainmenu_mountains,
		RECT{0, 0, 2720, 800}, 2720, 800);
}

void MainMenuState::Update()
{
	spr_bg.DrawSprite();
	spr_mountainFar.DrawSprite();
	spr_backGroundTress.DrawSprite();
	spr_foreGroundTrees.DrawSprite();
	spr_mountains.DrawSprite();

	//KojeomGameUI::UIBegin("mainmenu");
	//KojeomGameUI::UISetWindowPos(ImVec2(512, 480));
	//KojeomGameUI::UIButton("", ImVec2(384, 96));
	//KojeomGameUI::UIEnd();
}

void MainMenuState::Release()
{
	// to do
}
