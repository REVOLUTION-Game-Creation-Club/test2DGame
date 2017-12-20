#include "stdafx.h"
#include "main.h"
//
// Globals
//
IDirect3DDevice9* Device = 0;
// camera
Simple2DCamera* mainCamera;

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
	D3DXMatrixOrthoOffCenterLH(&proj, 0.0f, 1024.0f, 768.0f, 0.0f, 0.0f, 1.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	//
	// test for 2d game class
	
	mainCamera = Simple2DCamera::GetInstance();
	mainCamera->SetDevice(Device);
	mainCamera->Init(1024.0f, 768.0);

	//
	KojeomD3DUtil::GetInstance()->SetD3DDevice(Device);
	//
	GameStateManager::GetInstance()->InsertState(GAME_STATE::MAIN_MENU);
	return true;
}

// 프로그램 종료 시 호출되는 클린업.
void Cleanup()
{
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
		// imgui test
		KojeomGameUI::NewFrame();
		GameStateManager::GetInstance()->GetCurrentState()->Update();
		KojeomGameUI::EndFrame();
		KojeomGameUI::Render();

		Device->EndScene();
		// Swap the back and front buffers.
		Device->Present(0, 0, 0, 0);

		//late 
		GameStateManager::GetInstance()->LatePopState();
	}
	return true;
}

//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
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
			
		//if (wParam == VK_LEFT) playerObject->Move(-32, 0);
		//else if (wParam == VK_RIGHT) playerObject->Move(32, 0);
		//else if (wParam == VK_UP) playerObject->Move(0, -32);
		//else if (wParam == VK_DOWN) playerObject->Move(0, 32);
	
		//mainCamera->GetInstance()->FollowPlayer(playerObject->GetObjectPostion().x, playerObject->GetObjectPostion().y);
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
