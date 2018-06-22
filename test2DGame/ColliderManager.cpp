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
	for (int idx = 0; idx < TMX_MAP_TYPE::MAP_TOTAL_NUM; idx++) {
		auto mapType = (TMX_MAP_TYPE)idx;
		auto colls = TMXParser::GetInstance()->
			GetMapData(mapType).collObjects;
		for each (auto coll in colls)
		{
			// �÷��̾�� �� �������� �浹 ó���� ������ ����
			// �������� ���� tile�� collider ũ�⺸�� box2d�� �۰� �����Ѵ�.
			Box2DCollider box2dColl;
			box2dColl.MakeAABB(D3DXVECTOR3(coll.x + MAP_COLLIDER_BOUND_OFFSET,
				coll.y + MAP_COLLIDER_BOUND_OFFSET, 0.0f),
				D3DXVECTOR3(coll.x + coll.width - MAP_COLLIDER_BOUND_OFFSET,
					coll.y + coll.height - MAP_COLLIDER_BOUND_OFFSET, 0.0f));
			mapColliders[mapType].push_back(box2dColl);
		}
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
	for each (auto mapColl in mapColliders[curMapType])
	{
		if (mapColl.IsInterSectAABB(box2DColl)) return true;
	}
	return false;
}

void ColliderManager::SetCurrentMapType(TMX_MAP_TYPE mapType)
{
	curMapType = mapType;
}
