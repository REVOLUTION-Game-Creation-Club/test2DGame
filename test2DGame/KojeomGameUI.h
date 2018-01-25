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
	static bool Init(void* hwnd, IDirect3DDevice9* device);
	static void ResetRendering();
	static void Release();
	static void NewFrame();
	static void EndFrame();
	static void Render();
	static void InputProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void PopStyleColor(int count);
	static void PushStyleColor(ImGuiCol idx, const ImVec4& col);

	//
	static void UIBegin(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0);
	static void UIBegin(const char* name, bool* p_open, const ImVec2& size_on_first_use, float bg_alpha_override, ImGuiWindowFlags flags);
	static void UIEnd();
	static bool UIButton(const char* label, const ImVec2 size);
	static void UISetWindowPos(const ImVec2& pos, ImGuiCond cond = 0);
	static void UISetWindowSize(const ImVec2& size, ImGuiCond cond = 0);

	Ray static CalcPickingRay(int x, int y, IDirect3DDevice9* device);
};

