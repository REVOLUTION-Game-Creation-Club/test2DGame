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
	//�� ������Ʈ���� �������̱⿡, AABB�� �������� ����.
	vector<Box2DCollider> mapColliders;
};

