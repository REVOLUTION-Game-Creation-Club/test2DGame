#pragma once
#include "GameObjectFactory.h"
#include "Player.h"

class PlayerFactory : public GameObjectFactory
{
public:
	PlayerFactory();
	~PlayerFactory() override;

protected:
	virtual GameObject* CreateGameObject() override;
};

