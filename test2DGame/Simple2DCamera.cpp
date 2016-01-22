#include "Simple2DCamera.h"

//singleTon instance init
Simple2DCamera* Simple2DCamera::instance = nullptr;

Simple2DCamera::Simple2DCamera()
{
}

Simple2DCamera::~Simple2DCamera()
{
	if (instance != nullptr) delete instance;
	if (device != nullptr) delete device;
}

Simple2DCamera* Simple2DCamera::GetInstance()
{	
	if (instance == nullptr)
	{
		instance = new Simple2DCamera();
		return instance;
	}
	else return instance;
}

void Simple2DCamera::Init(float _viewWidth, float _viewHeight)
{
	cameraPosition = { 0, 0, 0 };

	viewHalfWidth = _viewWidth / 2;
	viewHalfHeight = _viewHeight / 2;

	D3DXMATRIX matLookAt;
	D3DXMatrixTranslation(&matLookAt, viewHalfWidth, viewHalfHeight, 0.0f);

	device->SetTransform(D3DTS_VIEW, &matLookAt);

}

void Simple2DCamera::SetDevice(IDirect3DDevice9* _device)
{
	if (_device != nullptr) device = _device;
	else MessageBox(0, L"Simple2DCamera SetDevice() - devicePtr failed", 0, 0);
}

//test func ( 아직 수정이 필요하다. )
void Simple2DCamera::Move(FLOAT _x, FLOAT _y)
{
	D3DXMATRIX setTransMat;
	D3DXMatrixTranslation(&setTransMat, _x, _y, 0.0f);
	device->SetTransform(D3DTS_VIEW, &setTransMat);

	D3DXMATRIX getTransMat;
	device->GetTransform(D3DTS_VIEW, &getTransMat);

	cameraPosition += D3DXVECTOR3(getTransMat._41, getTransMat._42, 0.0f);
}

void Simple2DCamera::FollowPlayer(FLOAT playerX, FLOAT playerY)
{
	cameraPosition = D3DXVECTOR3(playerX, playerY, 0.0f);

	D3DXMATRIX matLookAt;
	D3DXMatrixTranslation(&matLookAt, -playerX + viewHalfWidth, -playerY + viewHalfHeight, 0.0f);
	
	device->SetTransform(D3DTS_VIEW, &matLookAt);
}