#include "KojeomGameUI.h"



KojeomGameUI::KojeomGameUI()
{
}


KojeomGameUI::~KojeomGameUI()
{
}

void KojeomGameUI::Init(void* hwnd, IDirect3DDevice9* device)
{
	ImGui_ImplDX9_Init(hwnd, device);
}

void KojeomGameUI::ResetRendering()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	ImGui_ImplDX9_CreateDeviceObjects();
}

void KojeomGameUI::Release()
{
	ImGui_ImplDX9_Shutdown();
}

void KojeomGameUI::NewFrame()
{
	ImGui_ImplDX9_NewFrame();
}

void KojeomGameUI::EndFrame()
{
	ImGui::EndFrame();
}

void KojeomGameUI::Render()
{
	ImGui::Render();
}

void KojeomGameUI::InputProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
}


void KojeomGameUI::UIBegin(const char* name, bool* p_open,  ImGuiWindowFlags flags)
{
	ImGui::Begin(name, p_open, flags);
}

void KojeomGameUI::UIBegin(const char * name, bool * p_open, const ImVec2 & size_on_first_use, float bg_alpha_override, ImGuiWindowFlags flags)
{
	ImGui::Begin(name, p_open, size_on_first_use, bg_alpha_override, flags);
}

void KojeomGameUI::UIEnd()
{
	ImGui::End();
}

bool KojeomGameUI::UIButton(const char * label, const ImVec2 size)
{
	return ImGui::Button(label, size);
}

void KojeomGameUI::UISetWindowPos(const ImVec2 & pos, ImGuiCond cond)
{
	ImGui::SetWindowPos(pos, cond);
}

void KojeomGameUI::UISetWindowSize(const ImVec2 & size, ImGuiCond cond)
{
	ImGui::SetWindowSize(size, cond);
}

Ray KojeomGameUI::CalcPickingRay(int x, int y ,IDirect3DDevice9* device)
{
	float px = 0.0f;
	float py = 0.0f;

	D3DVIEWPORT9 vp;
	device->GetViewport(&vp);
	D3DXMATRIX proj;
	device->GetTransform(D3DTS_PROJECTION, &proj);

	px = (((2.0f * x) / vp.Width) - 1.0f) / proj(0, 0);
	py = (((-2.0f * y) / vp.Height) + 1.0f) / proj(1, 1);

	Ray ray;
	ray.origin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ray.direction = D3DXVECTOR3(px, py, 1.0f);

	return ray;
}