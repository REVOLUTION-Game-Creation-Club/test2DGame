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
}


ColliderManager::~ColliderManager()
{
}

void ColliderManager::Update()
{
}

bool ColliderManager::IsCollideWithMapObject(Box2DCollider box2DColl)
{
	return false;
}
