#pragma once
#include <d3dx9.h>
#include "imgui\imgui_impl_dx9.h"
struct Ray
{
public:
	D3DXVECTOR3 origin;
	D3DXVECTOR3 direction;
};

// imgui 라이브러리를 래핑해서 사용하는 클래스.
class KojeomGameUI
{
public:
	KojeomGameUI();
	~KojeomGameUI();
	static void Init(void* hwnd, IDirect3DDevice9* device);
	static void ResetRendering();
	static void Release();
	static void NewFrame();
	static void EndFrame();
	static void Render();
	static void InputProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	Ray static CalcPickingRay(int x, int y, IDirect3DDevice9* device);
};

