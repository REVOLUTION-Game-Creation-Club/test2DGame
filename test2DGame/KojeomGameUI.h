#pragma once
#include <d3dx9.h>

struct Ray
{
public:
	D3DXVECTOR3 origin;
	D3DXVECTOR3 direction;
};
class KojeomGameUI
{
public:
	KojeomGameUI();
	~KojeomGameUI();
	Ray static CalcPickingRay(int x, int y, IDirect3DDevice9* device);
};

