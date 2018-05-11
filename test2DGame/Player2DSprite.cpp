#include "Player2DSprite.h"



Player2DSprite::Player2DSprite()
{
}
Player2DSprite::~Player2DSprite()
{
	printf("Player2DSprite release...\n");
	if (spriteTexture2D != nullptr) spriteTexture2D->Release();
	if (spriteObject != nullptr) spriteObject->Release();
}

void Player2DSprite::Init(IDirect3DDevice9* _d3dDevice, string _spriteFileName, RECT _rect, unsigned int textureWidth, unsigned int textureHeight) {
	d3d9Device = _d3dDevice;
	spriteName = std::make_unique<string>(_spriteFileName);
	spriteRect = _rect;
	spritePosition = { 0, 0, 0 };
	spriteCenterPos = { 0, 0, 0 };
	spriteAlphaColor = { 1, 1, 1, 1 };
	D3DXMatrixIdentity(&transMatrix);

	texturePixelWidth = textureWidth;
	texturePixelHeight = textureHeight;

	CreateSprite();
	CreateTexture2D();
}

void Player2DSprite::DrawSprite()
{
	spriteObject->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

	HRESULT hr = spriteObject->Draw(spriteTexture2D, &spriteRect, &spriteCenterPos, NULL, spriteAlphaColor);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"DrawSprite() - FAILED");
	spriteObject->End();
}

void Player2DSprite::TranslateSprite(FLOAT _x, FLOAT _y)
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

void Player2DSprite::SetSpriteRect(RECT _spriteRect)
{
	spriteRect = _spriteRect;
}

void Player2DSprite::SetSpritePos(D3DXVECTOR3 _pos)
{
	spritePosition = _pos;
}

RECT Player2DSprite::GetSpriteRect()
{
	return spriteRect;
}

D3DXVECTOR3 Player2DSprite::GetSpritePos()
{
	return spritePosition;
}

void Player2DSprite::CreateSprite()
{

	HRESULT hr = D3DXCreateSprite(d3d9Device, &spriteObject);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"CreateSprite() - FAILED");
}

void Player2DSprite::CreateTexture2D()
{
	HRESULT hr = D3DXCreateTextureFromFileEx(d3d9Device,
		StringUtil::ConvertCharToWchar(spriteName.get()), texturePixelWidth,
		texturePixelHeight, 0, D3DUSAGE_RENDERTARGET, D3DFORMAT::D3DFMT_UNKNOWN,
		D3DPOOL::D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &spriteTexture2D);
	if (hr != S_OK) kojeomDebugLogger::MessageBoxLog(L"CreateTexture2D() - FAILED");
}


