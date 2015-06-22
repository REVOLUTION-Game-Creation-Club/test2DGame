// test2DGame.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "test2DGame.h"

//
// Globals
//
IDirect3DDevice9* Device = 0;
Game2DSprite* testSprite;
GameMap* testGameMap;
TMXParser* testTmxparser;
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
{	//136, 192
	RECT rt = { 0, 0, 136, 96 };
	testSprite = new Game2DSprite(Device, "Images/player.png", rt);
	RECT rt2 = { 32, 0, 64, 32 };
	testGameMap = new GameMap("GameResources/test5.tmx", Device, "GameResources/tileb.png", rt2);
	
	
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
 		testSprite->DrawSprite(); // order : 1

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
		if (wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		if (wParam == VK_RIGHT)
		{
			testSprite->TranslateSprite(10, 0);
		}
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}
