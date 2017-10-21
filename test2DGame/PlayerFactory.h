#pragma once
#include "GameObjectFactory.h"
#include "Player.h"

class PlayerFactory : public GameObjectFactory
{
public:
	PlayerFactory();
	virtual ~PlayerFactory();

protected:
	GameObject* CreateGameObject() override;
};

