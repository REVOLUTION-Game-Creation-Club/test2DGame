#include "KojeomD3DUtil.h"

KojeomD3DUtil* KojeomD3DUtil::instance = nullptr;

KojeomD3DUtil::KojeomD3DUtil()
{
	// to do
}


KojeomD3DUtil * KojeomD3DUtil::GetInstance()
{
	if (instance == nullptr) instance = new KojeomD3DUtil();
	return instance;
}

void KojeomD3DUtil::SetD3DDevice(IDirect3DDevice9 * _device)
{
	device = _device;
}

IDirect3DDevice9 * KojeomD3DUtil::GetD3DDevice()
{
	return device;
}

KojeomD3DUtil::~KojeomD3DUtil()
{
}
