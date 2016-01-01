#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Simple2DCamera
{
public:
	

	void Move(FLOAT _x, FLOAT _y);
	void FollowPlayer(FLOAT playerX, FLOAT playerY);
	void SetDevice(IDirect3DDevice9* _device);
	void Init(float _viewWidth, float _viewHeight);
	static Simple2DCamera* GetInstance();

private:
	Simple2DCamera();
	~Simple2DCamera();

	static Simple2DCamera* instance;
	D3DXVECTOR3 cameraPosition;
	IDirect3DDevice9* device;

	float viewHalfWidth;
	float viewHalfHeight;
};

