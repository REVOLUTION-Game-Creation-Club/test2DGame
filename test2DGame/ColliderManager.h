#pragma once
#include "TMXParser.h"
#include "Box2DCollider.h"
#include <vector>
using namespace std;

#define MAP_COLLIDER_BOUND_OFFSET 4.0f

class ColliderManager
{
public:
	static ColliderManager* GetInstance();
	~ColliderManager();
	void Update();
	bool IsCollideWithMapObject(Box2DCollider box2DColl);
private:
	ColliderManager();
	void CreateMapColliders();
	static ColliderManager* instance;
	//맵 오브젝트들은 고정적이기에, AABB도 변할일이 없다.
	vector<Box2DCollider> mapColliders;
};

