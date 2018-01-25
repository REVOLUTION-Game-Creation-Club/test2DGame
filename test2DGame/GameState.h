#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <WinUser.h>
//게임 스테이트 클래스.
// Init : 스테이트가 활성화 되기전에 초기화 하는 메서드.
// Start : 스테이트가 활성화 되기 직전에 특정 행위를 하는 메서드.
// Update : 스테이트가 활성화중에 이루어지는 여러 행위를 하는 메서드.
class GameState
{
public:
	virtual void Init(IDirect3DDevice9* _d3dDevice) = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;
	virtual void InputUpdate(UINT msg, WPARAM wParam) = 0;
	virtual ~GameState() {};
protected:
	bool isStarted;
};