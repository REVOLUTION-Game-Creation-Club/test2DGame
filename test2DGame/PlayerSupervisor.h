#pragma once
#include "GameObject.h"
#include <memory>
class PlayerSupervisor{
public:
	static PlayerSupervisor* GetInstance();
	void SetPlayerObject(GameObject* playerObject);
	GameObject* GetPlayerObject();
	~PlayerSupervisor();
private:
	static PlayerSupervisor* instance;
	PlayerSupervisor();
	GameObject* player;
};

