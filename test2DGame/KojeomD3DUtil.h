#pragma once
#include <d3dx9.h>
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

