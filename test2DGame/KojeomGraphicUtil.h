#pragma once
#include <d3dx9.h>

// test 구조체.
struct KojeomVertex
{
public:
	float x, y, z;
	KojeomVertex(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	static const DWORD FVF;
};

// test 클래스.
class KojeomGraphicUtil
{
public:
	void Init(IDirect3DDevice9* device);
	void Release();
	IDirect3DVertexBuffer9* GetVertexBuffer();
	static KojeomGraphicUtil* GetInstance();
	~KojeomGraphicUtil();

private:
	IDirect3DVertexBuffer9* vertexBuffer;
	KojeomGraphicUtil();
	static KojeomGraphicUtil* instance;
};

