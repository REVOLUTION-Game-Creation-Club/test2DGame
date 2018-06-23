#include "Simple2DCamera.h"


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
	if (instance == nullptr) instance = new Simple2DCamera();
	return instance;
}
//singleTon instance init
Simple2DCamera* Simple2DCamera::instance = nullptr;


float Simple2DCamera::GetViewWidth()
{
	return viewWidth;
}

float Simple2DCamera::GetViewHeight()
{
	return viewHeight;
}

void Simple2DCamera::Init(float _viewWidth, float _viewHeight)
{
	cameraPosition = { 0, 0, 0 };

	viewWidth = _viewHeight;
	viewHeight = _viewHeight;

	//D3DXMATRIX matLookAt;
	//D3DXMatrixTranslation(&matLookAt, viewHalfWidth, viewHalfHeight, 0.0f);
	//device->SetTransform(D3DTS_VIEW, &matLookAt);
}

void Simple2DCamera::SetDevice(IDirect3DDevice9* _device)
{
	if (_device != nullptr) device = _device;
	else kojeomDebugLogger::MessageBoxLog(L"Simple2DCamera SetDevice() - devicePtr failed");
}

//test func ( ���� ������ �ʿ��ϴ�. )
void Simple2DCamera::Move(FLOAT x, FLOAT y)
{
	D3DXMATRIX setTransMat;
	D3DXMatrixTranslation(&setTransMat, x, y, 0.0f);
	device->SetTransform(D3DTS_VIEW, &setTransMat);

	D3DXMATRIX getTransMat;
	device->GetTransform(D3DTS_VIEW, &getTransMat);

	cameraPosition += D3DXVECTOR3(getTransMat._41, getTransMat._42, 0.0f);
}

void Simple2DCamera::Move(D3DXVECTOR3 vec){
	D3DXMATRIX setTransMat;
	D3DXMatrixTranslation(&setTransMat, vec.x, vec.y, 0.0f);
	device->SetTransform(D3DTS_VIEW, &setTransMat);

	D3DXMATRIX getTransMat;
	device->GetTransform(D3DTS_VIEW, &getTransMat);

	cameraPosition += D3DXVECTOR3(getTransMat._41, getTransMat._42, 0.0f);
}

void Simple2DCamera::FollowObject(FLOAT x, FLOAT y){
	cameraPosition = D3DXVECTOR3(x, y, 0.0f);

	D3DXMATRIX matLookAt;
	D3DXMatrixTranslation(&matLookAt, -x + viewWidth / 2,
		-y + viewHeight / 2, 0.0f);

	device->SetTransform(D3DTS_VIEW, &matLookAt);
}

void Simple2DCamera::FollowObject(D3DXVECTOR3 vec){
	cameraPosition = vec;

	D3DXMATRIX matLookAt;
	D3DXMatrixTranslation(&matLookAt, -vec.x + viewWidth / 2,
		-vec.y + viewHeight / 2, 0.0f);

	device->SetTransform(D3DTS_VIEW, &matLookAt);
}
