#include "Game2DSprite.h"


Game2DSprite::Game2DSprite(IDirect3DDevice9* _d3dDevice, char* _spriteFileName, RECT _rect)
{
	d3d9Device = _d3dDevice;
	spriteName = _spriteFileName;
	spriteRect = _rect;
	spritePosition = { 0, 0, 0 };
	spriteAlphaColor = { 1, 1, 1, 1 };

	D3DXMatrixIdentity(&accumuMatrix);

	CreateSprite();
	CreateTexture2D();
}


Game2DSprite::~Game2DSprite()
{
	spriteTexture2D->Release();
	spriteObject->Release();
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
	/*D3DXCreateTextureFromFileEx(d3d9Device, ConvertCharToWchar(spriteName),
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		D3DFMT_FROM_FILE,
		D3DPOOL_MANAGED,
		0x01,
		0x01,
		0x00FFFFFF,
		nullptr,
		nullptr,
		&spriteTexture2D);*/
}

void Game2DSprite::DrawSprite()
{
	spriteObject->Begin(D3DXSPRITE_ALPHABLEND);

	HRESULT hr = spriteObject->Draw(spriteTexture2D, &spriteRect, nullptr, &spritePosition, spriteAlphaColor);
	if (hr != S_OK) MessageBox(0, L"DrawSprite() - FAILED", 0, 0);
	
	spriteObject->End();
}

void Game2DSprite::TranslateSprite(FLOAT x, FLOAT y)
{
	D3DXMATRIX matrix;
	accumuMatrix *= *(D3DXMatrixTranslation(&matrix, x, y, 0));

	HRESULT hr = spriteObject->SetTransform(&accumuMatrix);
	if (hr != S_OK) MessageBox(0, L"TransformSprite() - FAILED", 0, 0);
}

char* Game2DSprite::ConvertWcharToChar(wchar_t* str)
{
	//��ȯ�� char* ���� ����
	char* pStr;

	//�Է¹��� wchar_t ������ ���̸� ����
	int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);

	//char* �޸� �Ҵ�
	pStr = new char[strSize];

	//�� ��ȯ
	WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);

	return pStr;
}
wchar_t* Game2DSprite::ConvertCharToWchar(char* str)
{
	//wchar_t�� ���� ����
	wchar_t* pStr;
	//��Ƽ ����Ʈ ũ�� ��� ���� ��ȯ
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);

	//wchar_t �޸� �Ҵ�
	pStr = new WCHAR[strSize];
	//�� ��ȯ
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);

	return pStr;
}
