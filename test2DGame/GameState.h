#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <WinUser.h>
//���� ������Ʈ Ŭ����.
// Init : ������Ʈ�� Ȱ��ȭ �Ǳ����� �ʱ�ȭ �ϴ� �޼���.
// Start : ������Ʈ�� Ȱ��ȭ �Ǳ� ������ Ư�� ������ �ϴ� �޼���.
// Update : ������Ʈ�� Ȱ��ȭ�߿� �̷������ ���� ������ �ϴ� �޼���.
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