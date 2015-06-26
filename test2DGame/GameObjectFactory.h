#pragma once

enum GAMEOBJECT_TYPE { PLAYER, ENEMY, NPC, BUILDING };

class GameObjectFactory
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();
	

	//factory method
	virtual void CreateGameObject() = 0;
};

