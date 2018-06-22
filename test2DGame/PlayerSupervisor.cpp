#include "PlayerSupervisor.h"

PlayerSupervisor* PlayerSupervisor::instance = nullptr;

PlayerSupervisor::PlayerSupervisor(){
}


PlayerSupervisor * PlayerSupervisor::GetInstance()
{
	if (instance == nullptr) {
		instance = new PlayerSupervisor();
	}
	return instance;
}

void PlayerSupervisor::SetPlayerObject(GameObject* playerObject){
	player = playerObject;
}

GameObject * PlayerSupervisor::GetPlayerObject()
{
	return player;
}

PlayerSupervisor::~PlayerSupervisor(){
}
