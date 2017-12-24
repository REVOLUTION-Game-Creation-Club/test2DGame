#pragma once
#include <d3dx9.h>

// DirectX9 Device를 가지고 있는 클래스.
// 기능 테스트에 사용하려고 쓰는 임시클래스. 
class KojeomD3DUtil
{
public:
	static KojeomD3DUtil* GetInstance();
	void SetD3DDevice(IDirect3DDevice9* _device);
	IDirect3DDevice9* GetD3DDevice();
	~KojeomD3DUtil();
private:
	KojeomD3DUtil();
	static KojeomD3DUtil* instance;
	IDirect3DDevice9* device;
};

