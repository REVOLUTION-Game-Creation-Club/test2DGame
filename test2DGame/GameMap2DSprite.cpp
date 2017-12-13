#include "GameMap2DSprite.h"



GameMap2DSprite::GameMap2DSprite()
{
}


GameMap2DSprite::~GameMap2DSprite()
{
	if (spriteTexture2D != nullptr) spriteTexture2D->Release();
	if (spriteObject != nullptr) spriteObject->Release();
}

void GameMap2DSprite::Init(IDirect3DDevice9 * _d3dDevice, char * _spriteFileName, RECT _rect)
{
	d3d9Device = _d3dDevice;
	spriteName = _spriteFileName;
	spriteRect = _rect;
	spritePosition = { 0, 0, 0 };
	spriteCenterPos = { 0, 0, 0 };
	spriteAlphaColor = { 1, 1, 1, 1 };
	D3DXMatrixIdentity(&transMatrix);

	CreateSprite();
	CreateTexture2D();
}

void GameMap2DSprite::BeginDraw() {
	spriteObject->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}
void GameMap2DSprite::EndDraw() {
	spriteObject->End();
}


void GameMap2DSprite::DrawSprite()
{
	HRESULT hr = spriteObject->Draw(spriteTexture2D, &spriteRect, &spriteCenterPos, &spritePosition, spriteAlphaColor);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"DrawSprite() - FAILED");
}


void GameMap2DSprite::TranslateSprite(FLOAT _x, FLOAT _y)
{
	//SetTransForm
	D3DXMATRIX temp;
	D3DXMatrixTranslation(&temp, _x, _y, 0);
	transMatrix._41 += temp._41;
	transMatrix._42 += temp._42;

	HRESULT hr = spriteObject->SetTransform(&transMatrix);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"TransformSprite() - FAILED");

	//GetTransForm
	//D3DXMATRIX getTransMatrix;
	//spriteObject->GetTransform(&getTransMatrix);
	//spritePosition += D3DXVECTOR3(getTransMatrix._41, getTransMatrix._42, 0.0f);
	spritePosition += D3DXVECTOR3(_x, _y, 0.0f);
}

void GameMap2DSprite::SetSpriteRect(RECT _spriteRect)
{
	spriteRect = _spriteRect;
}

void GameMap2DSprite::SetSpritePos(D3DXVECTOR3 _pos)
{
	spritePosition = _pos;
}

RECT GameMap2DSprite::GetSpriteRect()
{
	return spriteRect;
}

D3DXVECTOR3 GameMap2DSprite::GetSpritePos()
{
	return spritePosition;
}

void GameMap2DSprite::CreateSprite()
{
	HRESULT hr = D3DXCreateSprite(d3d9Device, &spriteObject);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"CreateSprite() - FAILED");
}

void GameMap2DSprite::CreateTexture2D()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3d9Device, StringUtil::ConvertCharToWchar(spriteName), &spriteTexture2D);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"CreateTexture2D() - FAILED");
}
