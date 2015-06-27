#pragma once
#include "GameObject.h"
#include "Player.h"

enum GAMEOBJECT_TYPE { PLAYER, ENEMY, NPC, BUILDING };

class GameObjectFactory
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();
	GameObject* ProduceGameObject(GAMEOBJECT_TYPE _gameObjectType);

private:
	//factory method
	virtual GameObject* CreateGameObject() = 0;
};

