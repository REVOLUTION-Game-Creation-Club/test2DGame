#pragma once
#include "GameState.h"
#include "WorldMap.h"
#include "PlayerFactory.h"
#include "Player2DSprite.h"
#include "Game2DSprite.h"
#include "GameObjectFactory.h"
#include "PlayerCharAnimation.h"
#include "Simple2DCamera.h"
#include "KojeomGameUI.h"
#include "ColliderManager.h"
#include "PlayerSupervisor.h"
#include "GameMapUtil.h"
#include <memory>
class InGameState :
	public GameState
{
public:
	InGameState();
	~InGameState() override;

	// Inherited via GameState
	virtual void Init(IDirect3DDevice9 * _d3dDevice) override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void InputUpdate(UINT msg, WPARAM wParam) override;
private:
	// map
	std::unique_ptr<WorldMap> worldMap;
	//object
	std::unique_ptr<Game2DSprite> playerSprite;
	std::unique_ptr<GameObjectFactory> playerFactory;
	std::unique_ptr<GameObject> playerObject;
	void PlayerMoveUpdate(float moveX, float moveY);
	void WayoutColliderUpdate();
};

