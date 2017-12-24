#pragma once
#include "GameState.h"
#include "WorldMap.h"
#include "PlayerFactory.h"
#include "Player2DSprite.h"
#include "Game2DSprite.h"
#include "GameObjectFactory.h"
#include "Animation.h"
#include "Simple2DCamera.h"
#include "KojeomGameUI.h"
class InGameState :
	public GameState
{
public:
	InGameState();
	~InGameState() override;

	// Inherited via GameState
	virtual void Init(IDirect3DDevice9 * _d3dDevice) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	// map
	WorldMap* worldMap;
	//object
	Game2DSprite* playerSprite;
	GameObjectFactory* playerFactory;
	GameObject* playerObject;
	// ani
	Animation playerTestAni;
};

