#pragma once
#include "Collider.h"
class Box2DCollider :
	public Collider
{
public:
	Box2DCollider();
	~Box2DCollider() override;
	
	virtual void Update() override;
	void MakeAABB(D3DXVECTOR3 min, D3DXVECTOR3 max);
	void MakeAABB(D3DXVECTOR3 points[], unsigned int len);
	bool IsInterSectPoint(D3DXVECTOR3 point);
	bool IsInterSectAABB(Box2DCollider box2dColl);

	D3DXVECTOR3 GetMinExtent();
	D3DXVECTOR3 GetMaxExtent();
private:
	D3DXVECTOR3 minExtent;
	D3DXVECTOR3 maxExtent;
};

