#pragma once
#include "GameObject.h"
#include "Player.h"

enum GAMEOBJECT_TYPE
{ 
	PLAYER = 0,
	ENEMY = 1,
	NPC = 2,
	BUILDING = 3 
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

