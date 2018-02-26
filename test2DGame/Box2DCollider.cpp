#include "Box2DCollider.h"



Box2DCollider::Box2DCollider()
{
}


Box2DCollider::~Box2DCollider()
{
}

void Box2DCollider::Update()
{
}

void Box2DCollider::MakeAABB(D3DXVECTOR3 min, D3DXVECTOR3 max)
{
	minExtent = min;
	maxExtent = max;
}

void Box2DCollider::MakeAABB(D3DXVECTOR3 points[], unsigned int len)
{
	minExtent = points[0];
	maxExtent = points[0];
	for (unsigned int idx = 1; idx < len; idx++)
	{
		if (points[idx].x < minExtent.x) minExtent.x = points[idx].x;
		else if (points[idx].x > maxExtent.x) maxExtent.x = points[idx].x;
		if (points[idx].y < minExtent.y) minExtent.y = points[idx].y;
		else if (points[idx].y > maxExtent.y) maxExtent.y = points[idx].y;
		if (points[idx].z < minExtent.z) minExtent.z = points[idx].z;
		else if (points[idx].z > maxExtent.z) maxExtent.z = points[idx].z;
	}
}

bool Box2DCollider::IsInterSectPoint(D3DXVECTOR3 point)
{
	if ((point.x > minExtent.x && point.x < maxExtent.x) &&
		(point.y > minExtent.y && point.y < maxExtent.y) &&
		(point.z > minExtent.z && point.z < maxExtent.z))
	{
		return true;
	}
	return false;
}

bool Box2DCollider::IsInterSectAABB(Box2DCollider box2dColl)
{
	if ((minExtent.x <= box2dColl.GetMaxExtent().x && maxExtent.x >= box2dColl.GetMinExtent().x) &&
		(minExtent.y <= box2dColl.GetMaxExtent().y && maxExtent.y >= box2dColl.GetMinExtent().y) &&
		(minExtent.z <= box2dColl.GetMaxExtent().z && maxExtent.z >= box2dColl.GetMinExtent().z))
	{
		return true;
	}
	return false;
}

D3DXVECTOR3 Box2DCollider::GetMinExtent()
{
	return minExtent;
}

D3DXVECTOR3 Box2DCollider::GetMaxExtent()
{
	return maxExtent;
}
