#pragma once
#include "TMXParser.h"
#include "Box2DCollider.h"
#include <vector>
using namespace std;
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
	vector<Box2DCollider> mapColliders;
};

