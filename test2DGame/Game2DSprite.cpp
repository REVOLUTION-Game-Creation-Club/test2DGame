#include "Game2DSprite.h"


Game2DSprite::Game2DSprite(IDirect3DDevice9* _d3dDevice, char* _spriteFileName, RECT _rect)
{
	d3d9Device = _d3dDevice;
	spriteName = _spriteFileName;
	spriteRect = _rect;
	spritePosition = { 0, 0, 0 };
	spriteCenterPos = { 0, 0, 0 };
	spriteAlphaColor = { 1, 1, 1, 1 };

	CreateSprite();
	CreateTexture2D();
	
}


Game2DSprite::~Game2DSprite()
{
	if (spriteTexture2D != nullptr) spriteTexture2D->Release();
	if (spriteObject != nullptr) spriteObject->Release();
	if (spriteName != nullptr) delete spriteName;
	if (d3d9Device != nullptr) delete d3d9Device;
}

void Game2DSprite::CreateSprite()
{
	
	HRESULT hr = D3DXCreateSprite(d3d9Device, &spriteObject);
	if (hr != S_OK) MessageBox(0, L"CreateSprite() - FAILED", 0, 0);
}

void Game2DSprite::CreateTexture2D()
{
	HRESULT hr = D3DXCreateTextureFromFile(d3d9Device, ConvertCharToWchar(spriteName), &spriteTexture2D);
	if (hr != S_OK) MessageBox(0, L"CreateTexture2D() - FAILED", 0, 0);
}

void Game2DSprite::DrawSprite()
{
	spriteObject->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);

	HRESULT hr = spriteObject->Draw(spriteTexture2D, &spriteRect, &spriteCenterPos, &spritePosition, spriteAlphaColor);
	if (hr != S_OK) MessageBox(0, L"DrawSprite() - FAILED", 0, 0);
	
	spriteObject->End();
}

void Game2DSprite::TranslateSprite(FLOAT _x, FLOAT _y)
{
	//SetTransForm
	D3DXMATRIX setTransMatrix;
	D3DXMatrixTranslation(&setTransMatrix, _x, _y, 0);

	HRESULT hr = spriteObject->SetTransform(&setTransMatrix);
	if (hr != S_OK) MessageBox(0, L"TransformSprite() - FAILED", 0, 0);
	
	// GetTransForm
	D3DXMATRIX getTransMatrix;
	spriteObject->GetTransform(&getTransMatrix);
	spritePosition += D3DXVECTOR3(getTransMatrix._41, getTransMatrix._42, 0.0f);
}

void Game2DSprite::SetSpriteRect(RECT _spriteRect)
{
	spriteRect = _spriteRect;
}

void Game2DSprite::SetSpritePos(D3DXVECTOR3 _pos)
{
	spritePosition = _pos;
}
D3DXVECTOR3 Game2DSprite::GetSpritePos()
{
	return spritePosition;
}

void Game2DSprite::BeginSpriteForMAP()
{
	spriteObject->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void Game2DSprite::EndSpriteForMAP()
{
	spriteObject->End();
}
// must Begin and End func
void Game2DSprite::DrawSpriteForMAP()
{
	HRESULT hr = spriteObject->Draw(spriteTexture2D, &spriteRect, nullptr, &spritePosition, spriteAlphaColor);
	if (hr != S_OK) MessageBox(0, L"DrawSprite() - FAILED", 0, 0);
}

char* Game2DSprite::ConvertWcharToChar(wchar_t* str)
{
	//반환할 char* 변수 선언
	char* pStr;

	//입력받은 wchar_t 변수의 길이를 구함
	int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);

	//char* 메모리 할당
	pStr = new char[strSize];

	//형 변환
	WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);

	return pStr;
}
wchar_t* Game2DSprite::ConvertCharToWchar(char* str)
{
	//wchar_t형 변수 선언
	wchar_t* pStr;
	//멀티 바이트 크기 계산 길이 반환
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);

	//wchar_t 메모리 할당
	pStr = new WCHAR[strSize];
	//형 변환
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);

	return pStr;
}
