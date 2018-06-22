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
	CreateWayoutColliders();
}

void ColliderManager::CreateMapColliders()
{
	for (int idx = 0; idx < TMX_MAP_TYPE::MAP_TOTAL_NUM; idx++) {
		auto mapType = (TMX_MAP_TYPE)idx;
		auto colls = TMXParser::GetInstance()->
			GetMapData(mapType).collObjects;
		for (auto coll : colls){
			// 플레이어와 맵 지형간의 충돌 처리에 편리함을 위해
			// 맵툴에서 만든 tile의 collider 크기보다 box2d를 작게 설정한다.
			Box2DCollider box2dColl;
			box2dColl.MakeAABB(D3DXVECTOR3(coll.x + MAP_COLLIDER_BOUND_OFFSET,
				coll.y + MAP_COLLIDER_BOUND_OFFSET, 0.0f),
				D3DXVECTOR3(coll.x + coll.width - MAP_COLLIDER_BOUND_OFFSET,
					coll.y + coll.height - MAP_COLLIDER_BOUND_OFFSET, 0.0f));
			mapColliders[mapType].push_back(box2dColl);
		}
	}
}

void ColliderManager::CreateWayoutColliders(){
	for (int idx = 0; idx < TMX_MAP_TYPE::MAP_TOTAL_NUM; idx++) {
		auto mapType = (TMX_MAP_TYPE)idx;
		auto wayoutInfo = TMXParser::GetInstance()->GetMapData(mapType).wayoutInfo;
		for (auto wayout : wayoutInfo.wayouts) {
			Box2DCollider box2dColl;
			box2dColl.MakeAABB(D3DXVECTOR3(wayout.x + WAYOUT_COLLIDER_BOUND_OFFSET,
				wayout.y + WAYOUT_COLLIDER_BOUND_OFFSET, 0.0f),
				D3DXVECTOR3(wayout.x + wayout.width - WAYOUT_COLLIDER_BOUND_OFFSET,
					wayout.y + wayout.height - WAYOUT_COLLIDER_BOUND_OFFSET, 0.0f));
			//
			WayoutCollider wayoutColl;
			wayoutColl.box2dColl = box2dColl;
			wayoutColl.wayoutInfo = wayout;
			wayoutColliders[mapType].push_back(wayoutColl);
		}
	}
}


ColliderManager::~ColliderManager(){
}

void ColliderManager::Update(){
	if (PlayerSupervisor::GetInstance() != nullptr) {
		curMapType = PlayerSupervisor::GetInstance()->GetPlayerObject()->GetCurMapType();
	}
}

bool ColliderManager::IsCollideMapObject(Box2DCollider box2DColl){
	for(auto mapColl : mapColliders[curMapType]){
		if (mapColl.IsInterSectAABB(box2DColl)) return true;
	}
	return false;
}

WayoutCollideResult ColliderManager::IsCollideWayOut(Box2DCollider box2DColl){
	WayoutCollideResult result;
	result.isCollide = false;
	result.wayoutInfo.toDirection = "NONE";
	for (auto wayoutColl : wayoutColliders[curMapType]) {
		if (wayoutColl.box2dColl.IsInterSectAABB(box2DColl)) {
			result.isCollide = true;
			result.wayoutInfo = wayoutColl.wayoutInfo;
		}
	}
	return result;
}

void ColliderManager::SetCurrentMapType(TMX_MAP_TYPE mapType){
	curMapType = mapType;
}
