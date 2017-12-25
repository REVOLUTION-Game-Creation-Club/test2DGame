#include "KojeomGraphicUtil.h"

const DWORD KojeomVertex::FVF = D3DFVF_XYZ;
KojeomGraphicUtil* KojeomGraphicUtil::instance = nullptr;

KojeomGraphicUtil::KojeomGraphicUtil()
{
}


void KojeomGraphicUtil::Init(IDirect3DDevice9 * device)
{
	device->CreateVertexBuffer(
		3 * sizeof(KojeomVertex), // size in bytes
		D3DUSAGE_WRITEONLY, // flags
		KojeomVertex::FVF,        // vertex format
		D3DPOOL_MANAGED,    // managed memory pool
		&vertexBuffer,          // return create vertex buffer
		0);                 // not used - set to 0

	KojeomVertex* vertices;
	vertexBuffer->Lock(0, 0, (void**)&vertices, 0);

	vertices[0] = KojeomVertex(-1.0f, 0.0f, 2.0f);
	vertices[1] = KojeomVertex(0.0f, 1.0f, 2.0f);
	vertices[2] = KojeomVertex(1.0f, 0.0f, 2.0f);

	vertexBuffer->Unlock();
}

void KojeomGraphicUtil::Release()
{
	vertexBuffer->Release();
}

IDirect3DVertexBuffer9 * KojeomGraphicUtil::GetVertexBuffer()
{
	return vertexBuffer;
}

KojeomGraphicUtil * KojeomGraphicUtil::GetInstance()
{
	if (instance == nullptr) instance = new KojeomGraphicUtil();
	return instance;
}

KojeomGraphicUtil::~KojeomGraphicUtil()
{
}
