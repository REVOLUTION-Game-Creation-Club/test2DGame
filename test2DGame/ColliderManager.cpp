#include "ColliderManager.h"

ColliderManager* ColliderManager::instance = nullptr;

ColliderManager * ColliderManager::GetInstance()
{
	if (instance == nullptr) instance = new ColliderManager();
	return instance;
}

ColliderManager::ColliderManager()
{
	CreateMapColliders();
}

void ColliderManager::CreateMapColliders()
{
	// to do
	auto colls = TMXParser::GetInstance()->
		GetMapData(TMX_MAP_TYPE::GAME_MAP_0).collObjects;
	for each (auto coll in colls)
	{
		Box2DCollider box2dColl;
		box2dColl.MakeAABB(D3DXVECTOR3(coll.x - MAP_COLLIDER_BOUND_OFFSET, coll.y - MAP_COLLIDER_BOUND_OFFSET, 0.0f),
			D3DXVECTOR3(coll.x + coll.width - MAP_COLLIDER_BOUND_OFFSET, coll.y - MAP_COLLIDER_BOUND_OFFSET + coll.height, 0.0f));
		mapColliders.push_back(box2dColl);
	}
}


ColliderManager::~ColliderManager()
{
}

void ColliderManager::Update()
{
}

bool ColliderManager::IsCollideWithMapObject(Box2DCollider box2DColl)
{
	for each (auto mapColl in mapColliders)
	{
		if (mapColl.IsInterSectAABB(box2DColl)) return true;
	}
	return false;
}
