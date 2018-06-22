#include "MainMenuState.h"



MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init(IDirect3DDevice9* _d3dDevice)
{
	isStarted = false;
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
	spr_title.Init(_d3dDevice,
		FilePath::GetInstance()->mainmenu_title,
		RECT {0, 0, 514, 105}, 514, 105);
	spr_title.TranslateSprite(256.0f, 192.0f);
}

void MainMenuState::Start()
{
	if (isStarted) return;
	isStarted = true;
}

void MainMenuState::Update()
{
	spr_bg.DrawSprite();
	spr_mountainFar.DrawSprite();
	spr_backGroundTress.DrawSprite();
	spr_foreGroundTrees.DrawSprite();
	spr_mountains.DrawSprite();
	spr_title.DrawSprite();

	KojeomGameUI::UIBegin("mainmenu", 0, ImVec2(0,0), 0,
		ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
	KojeomGameUI::UISetWindowPos(ImVec2(384, 480));
	KojeomGameUI::UISetWindowSize(ImVec2(384, 128));
	if (KojeomGameUI::UIButton("Game Start", ImVec2(384, 96))){
		// to do
		GameStateManager::GetInstance()->InsertState(GAME_STATE::INGAME);
	};
	KojeomGameUI::UIEnd();
}

void MainMenuState::Release()
{
	// to do
	isStarted = false;
}

void MainMenuState::InputUpdate(UINT msg, WPARAM wParam)
{
}
