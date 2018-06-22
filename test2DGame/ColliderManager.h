#pragma once
#include "TMXParser.h"
#include "Box2DCollider.h"
#include "PlayerSupervisor.h"
#include <vector>
using namespace std;

#define MAP_COLLIDER_BOUND_OFFSET 4.0f
#define WAYOUT_COLLIDER_BOUND_OFFSET 10.0f
struct WayoutCollider {
public:
	Box2DCollider box2dColl;
	WayOut wayoutInfo;
};

struct WayoutCollideResult {
public:
	bool isCollide;
	WayOut wayoutInfo;
};

class ColliderManager
{
public:
	static ColliderManager* GetInstance();
	~ColliderManager();
	void Update();
	bool IsCollideMapObject(Box2DCollider box2DColl);
	WayoutCollideResult IsCollideWayOut(Box2DCollider box2DColl);
	void SetCurrentMapType(TMX_MAP_TYPE mapType);
private:
	ColliderManager();
	void CreateMapColliders();
	void CreateWayoutColliders();
	static ColliderManager* instance;
	//�� ������Ʈ���� �������̱⿡, AABB�� �������� ����.
	vector<Box2DCollider> mapColliders[TMX_MAP_TYPE::MAP_TOTAL_NUM];
	vector<WayoutCollider> wayoutColliders[TMX_MAP_TYPE::MAP_TOTAL_NUM];
	TMX_MAP_TYPE curMapType;
};

