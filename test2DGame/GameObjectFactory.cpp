#include "GameObjectFactory.h"


GameObjectFactory::GameObjectFactory()
{
}


GameObjectFactory::~GameObjectFactory()
{
}

GameObject* GameObjectFactory::ProduceGameObject(GAMEOBJECT_TYPE _gameObjectType)
{
	GameObject* obj;
	switch (_gameObjectType)
	{
	case GAMEOBJECT_TYPE::PLAYER :
		obj = CreateGameObject();
		break;
	default:
		obj = nullptr;
		break;
	}
	return obj;
}