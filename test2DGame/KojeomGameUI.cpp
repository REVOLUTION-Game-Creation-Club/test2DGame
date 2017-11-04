#include "KojeomGameUI.h"



KojeomGameUI::KojeomGameUI()
{
}


KojeomGameUI::~KojeomGameUI()
{
}

Ray KojeomGameUI::CalcPickingRay(int x, int y ,IDirect3DDevice9* device)
{
	float px = 0.0f;
	float py = 0.0f;

	D3DVIEWPORT9 vp;
	device->GetViewport(&vp);
	D3DXMATRIX proj;
	device->GetTransform(D3DTS_PROJECTION, &proj);

	px = (((2.0f * x) / vp.Width) - 1.0f) / proj(0, 0);
	py = (((-2.0f * y) / vp.Height) + 1.0f) / proj(1, 1);

	Ray ray;
	ray.origin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ray.direction = D3DXVECTOR3(px, py, 1.0f);

	return ray;
}