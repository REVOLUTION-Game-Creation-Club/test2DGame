#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "kojeomDebugLogger.h"

class Simple2DCamera
{
public:
	void Move(FLOAT x, FLOAT y);
	void Move(D3DXVECTOR3 vec);
	void FollowObject(FLOAT x, FLOAT y);
	void FollowObject(D3DXVECTOR3 vec);
	void SetDevice(IDirect3DDevice9* _device);
	void Init(float _viewWidth, float _viewHeight);
	static Simple2DCamera* GetInstance();

	float GetViewWidth();
	float GetViewHeight();
private:
	Simple2DCamera();
	~Simple2DCamera();

	static Simple2DCamera* instance;
	D3DXVECTOR3 cameraPosition;
	IDirect3DDevice9* device;

	float viewWidth;
	float viewHeight;;
};
