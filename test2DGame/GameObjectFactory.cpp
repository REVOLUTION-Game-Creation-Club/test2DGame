#include "GameObjectFactory.h"


GameObjectFactory::GameObjectFactory()
{
}


GameObjectFactory::~GameObjectFactory()
{
}

GameObject* GameObjectFactory::ProduceGameObject(GAMEOBJECT_TYPE _gameObjectType)
{
	switch (_gameObjectType)
	{
	case GAMEOBJECT_TYPE::PLAYER :
		return CreateGameObject();
		break;
	}
}