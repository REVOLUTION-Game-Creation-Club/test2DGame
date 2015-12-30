#include "stdafx.h"
#include "main.h"

//
// Globals
//
IDirect3DDevice9* Device = 0;
//
//test variables for 2d game class..
//
GameMap* testGameMap;
TMXParser* testTmxparser;

Game2DSprite* playerSprite;
GameObjectFactory* playerFactory;
GameObject* playerObject;

Simple2DCamera* mainCamera;

Animation* playerTestAni;

// test variables for antTweakBar( gui )
TwBar* testTwBar;

//
// Framework Functions Prototype
//
bool Setup();
void Cleanup();
bool Display(float timeDelta);
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE prevInstance,
	PSTR cmdLine,
	int showCmd)
{
	if (!d3d::InitD3D(hinstance,
		800, 680, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, L"InitD3D() - FAILED", 0, 0);
		return 0;
	}

	if (!Setup())
	{
		::MessageBox(0, L"Setup() - FAILED", 0, 0);
		return 0;
	}


	d3d::EnterMsgLoop(Display);

	Cleanup();

	Device->Release();

	return 0;
}


bool Setup()
{	
	//
	// Set projection matrix.
	//
	D3DXMATRIX proj;
	D3DXMatrixOrthoOffCenterLH(&proj, 0.0f, 800.0f, 680.0f, 0.0f, 0.0f, 1.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//
	// test for 2d game class
	//
	RECT mapDefaultRect = { 0, 0, 0, 0 };
	testGameMap = new GameMap("GameResources/test5.tmx", Device, "GameResources/tileb.png", mapDefaultRect);

	playerFactory = new PlayerFactory();
	playerObject = playerFactory->ProduceGameObject(GAMEOBJECT_TYPE::PLAYER);
	playerSprite = new Game2DSprite(Device, "GameResources/ch01.png", RECT{ 0, 0, 32, 42 });
	playerObject->SetSpriteObject(playerSprite);

	playerTestAni = new Animation();
	playerTestAni->SetSpriteObject(playerSprite);
	playerTestAni->SetDrawInfos(DrawInfo{ 96, 128, 0, 32, 0, 0, 42, 200 });

	mainCamera = Simple2DCamera::GetInstance();
	mainCamera->SetDevice(Device);
	mainCamera->Init();

	//testMap offset pos 
	testGameMap->Move(-400.0f, -340.0f);

	//test for antTweakBar( gui lib )
	TwInit(TW_DIRECT3D9, Device);
	TwWindowSize(200.0f , 150.0f);
	testTwBar = TwNewBar("Test_TwNewBar");
	
	return true;
}

void Cleanup()
{
	// Nothing to cleanup in this sample.
}

bool Display(float timeDelta)
{
	if (Device) // Only use Device methods if we have a valid device.
	{
		// Instruct the device to set each pixel on the back buffer black -
		// D3DCLEAR_TARGET: 0x00000000 (black) - and to set each pixel on
		// the depth buffer to a value of 1.0 - D3DCLEAR_ZBUFFER: 1.0f.
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		Device->BeginScene();

		testGameMap->DrawMap(); // order : 0
		playerObject->Draw(); // order : 1
		playerTestAni->DrawFrames();

		//antTweakBar draw
		TwDraw();

		Device->EndScene();
		// Swap the back and front buffers.
		Device->Present(0, 0, 0, 0);
	}
	return true;
}

//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) ::DestroyWindow(hwnd);
			
		if (wParam == VK_LEFT) playerObject->Move(-1, 0);
		else if (wParam == VK_RIGHT) playerObject->Move(1, 0);
		else if (wParam == VK_UP) playerObject->Move(0, -1);
		else if (wParam == VK_DOWN) playerObject->Move(0, 1);
		
		mainCamera->GetInstance()->FollowPlayer(playerObject->GetObjectPostion().x, playerObject->GetObjectPostion().y);
		break;
	}
	

	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}
