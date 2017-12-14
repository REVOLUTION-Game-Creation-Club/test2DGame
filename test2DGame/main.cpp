#include "stdafx.h"
#include "main.h"
//
// Globals
//
IDirect3DDevice9* Device = 0;

//test 
WorldMap* worldMap;
Game2DSprite* playerSprite;
GameObjectFactory* playerFactory;
GameObject* playerObject;

Simple2DCamera* mainCamera;

Animation* playerTestAni;

// sound test
GameSoundManager* gameSoundManager;

//gui test
TwBar* twBar;

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
		1024, 768, true, D3DDEVTYPE_HAL, &Device))
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
	
	playerFactory = new PlayerFactory();
	playerObject = playerFactory->ProduceGameObject(GAMEOBJECT_TYPE::PLAYER);
	playerSprite = new Player2DSprite();
	playerSprite->Init(Device, "GameResources/ch01.png", RECT{ 0, 0, 32, 42 });
	playerObject->SetSpriteObject(playerSprite);

	playerTestAni = new Animation();
	playerTestAni->SetSpriteObject(playerSprite);
	playerTestAni->SetDrawInfos(DrawInfo{ 96, 128, 0, 32, 0, 0, 42, 200 });

	mainCamera = Simple2DCamera::GetInstance();
	mainCamera->SetDevice(Device);
	mainCamera->Init(800.0f, 680.0);

	worldMap = new WorldMap(Device);

	gameSoundManager = new GameSoundManager();
	gameSoundManager->PlayGameSound(GAME_SOUND_TYPE::BGM_MAIN, 0.2f);

	//twgui test
	//TwInit(TW_DIRECT3D9, Device);
	//twBar = TwNewBar("TEST_GUI_WINDOW");

	return true;
}

// 프로그램 종료 시 호출되는 클린업.
void Cleanup()
{
	//twgui release..
	//TwTerminate();

	delete worldMap;
	delete playerObject;
	delete playerFactory;
	//gui shutdown..
	KojeomGameUI::Release();
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

		worldMap->Update(); // order : 0
		playerObject->Update(); // order : 1
		playerTestAni->DrawFrames();

		// twgui test
		//TwDraw();

		// imgui test
		KojeomGameUI::NewFrame();
		//////////////////////////////////////
		/////////// gui test codes..//////////
		//////////////////////////////////////
		ImGui::Begin("test");
		ImGui::SetWindowSize(ImVec2(384, 256));
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::Text("Hello from another window!");

		bool isWantCaptureMouse = ImGui::GetIO().WantCaptureMouse;
		if (isWantCaptureMouse)
			ImGui::Text("WantCaptureMouse TRUE");
		else
			ImGui::Text("WantCaptureMouse FALSE");

		if (ImGui::Button("ClickButton"))
		{
			// to do..
		}
		ImGui::End();
		////////////////////////////////////
		KojeomGameUI::EndFrame();
		KojeomGameUI::Render();

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
	// tw gui 
	//if (TwEventWin(hwnd, msg, wParam, lParam)) return 0;

	//ray 캐스팅 테스트용 변수.
	float x, y;
	Ray ray;
	// gui input..
	KojeomGameUI::InputProcess(hwnd, msg, wParam, lParam);

	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) ::DestroyWindow(hwnd);
			
		if (wParam == VK_LEFT) playerObject->Move(-32, 0);
		else if (wParam == VK_RIGHT) playerObject->Move(32, 0);
		else if (wParam == VK_UP) playerObject->Move(0, -32);
		else if (wParam == VK_DOWN) playerObject->Move(0, 32);
	
		mainCamera->GetInstance()->FollowPlayer(playerObject->GetObjectPostion().x, playerObject->GetObjectPostion().y);
		break;
	case WM_LBUTTONDOWN:
		//POINT mousePoint;
		//GetCursorPos(&mousePoint);
		//ScreenToClient(hwnd, &mousePoint);
		//// ray test.
		//ray = KojeomGameUI::CalcPickingRay(mousePoint.x, mousePoint.y, Device);
		//kojeomDebugLogger::MessageBoxLog(L"마우스 왼쪽 버튼 클릭.");
		break;
	case WM_SIZE:
		KojeomGameUI::ResetRendering();
		break;
	}
	

	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}
