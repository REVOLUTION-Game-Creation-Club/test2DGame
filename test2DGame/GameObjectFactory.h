#pragma once
#include "GameObject.h"
#include "Player.h"

enum class GAMEOBJECT_TYPE
{ 
	PLAYER,
	ENEMY,
	NPC,
	BUILDING 
};

class GameObjectFactory
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();
	GameObject* ProduceGameObject(GAMEOBJECT_TYPE _gameObjectType);

protected:
	//factory method
	virtual GameObject* CreateGameObject() = 0;
};

