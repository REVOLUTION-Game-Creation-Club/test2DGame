#include "PlayerFactory.h"


PlayerFactory::PlayerFactory()
{
}


PlayerFactory::~PlayerFactory()
{
}

GameObject* PlayerFactory::CreateGameObject()
{
	return new Player();
}