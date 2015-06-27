#pragma once
#include "GameObjectFactory.h"
#include "Player.h"

class PlayerFactory : public GameObjectFactory
{
public:
	PlayerFactory();
	virtual ~PlayerFactory();

private:
	virtual GameObject* CreateGameObject();
};

