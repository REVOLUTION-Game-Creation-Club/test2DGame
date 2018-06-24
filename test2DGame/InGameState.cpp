#include "InGameState.h"



InGameState::InGameState(){
}


InGameState::~InGameState(){

}

void InGameState::Init(IDirect3DDevice9 * _d3dDevice){
	isStarted = false;
	playerFactory = std::unique_ptr<GameObjectFactory>(new PlayerFactory());
	playerObject = std::unique_ptr<GameObject>(playerFactory->ProduceGameObject(GAMEOBJECT_TYPE::PLAYER));
	playerSprite = std::unique_ptr<Player2DSprite>(new Player2DSprite());
	playerSprite.get()->Init(_d3dDevice, FilePath::GetInstance()->chacracter01, RECT { 0, 0, 32, 32 },
		96, 128);
	playerObject->Init(playerSprite.get());
	playerObject->SetPositionedMapType(TMX_MAP_TYPE::MAIN_TOWN);
	//
	PlayerSupervisor::GetInstance()->SetPlayerObject(playerObject.get());

	// player offset 위치 적용.
	// - view 크기의 정중앙값을 offset으로 사용.
	// 임시로 96.0f를 x 값에 더하여 위치를 정한다. ( 테스트용.)
	D3DXVECTOR3 vec;
	vec.x = Simple2DCamera::GetInstance()->GetViewWidth() / 2;
	vec.y = Simple2DCamera::GetInstance()->GetViewHeight() / 2;
	playerObject->Move(vec);

	worldMap = std::make_unique<WorldMap>(_d3dDevice);
}

void InGameState::Start(){
	if (isStarted) return;
	isStarted = true;
}

void InGameState::Update(){
	worldMap->Update(); // order : 0
	playerObject->Update(); // order : 1
	ColliderManager::GetInstance()->Update();
}

void InGameState::Release(){
	isStarted = false;
}

void InGameState::InputUpdate(UINT msg, WPARAM wParam){
	float moveX = 0.0f, moveY = 0.0f;
	switch (msg){
	case WM_KEYDOWN:
		if (wParam == VK_LEFT){
			playerObject->SetLookDirection(LOOK_DIRECTION::left);
			moveX = -32.0f;
			moveY = 0.0f;
		}
		else if (wParam == VK_RIGHT){
			playerObject->SetLookDirection(LOOK_DIRECTION::right);
			moveX = 32.0f;
			moveY = 0.0f;
		}
		else if (wParam == VK_UP){
			playerObject->SetLookDirection(LOOK_DIRECTION::back);
			moveX = 0.0f;
			moveY = -32.0f;
		}
		else if (wParam == VK_DOWN){
			playerObject->SetLookDirection(LOOK_DIRECTION::forward);
			moveX = 0.0f;
			moveY = 32.0f;
		}
		PlayerMoveUpdate(moveX, moveY);
		WayoutColliderUpdate();
		Simple2DCamera::GetInstance()->FollowObject(playerObject->GetObjectPosition());
		break;
	}
}

void InGameState::PlayerMoveUpdate(float moveX, float moveY){
	Box2DCollider intersectTest;
	D3DXVECTOR3 min = playerObject->GetAABB().GetMinExtent();
	D3DXVECTOR3 max = playerObject->GetAABB().GetMaxExtent();
	intersectTest.MakeAABB(D3DXVECTOR3(min.x + moveX, min.y + moveY, 0.0f),
		D3DXVECTOR3(max.x + moveX, max.y + moveY, 0.0f));
	if (ColliderManager::GetInstance()->
		IsCollideMapObject(intersectTest) == false) {
		playerObject->Move(moveX, moveY);
	}
}

void InGameState::WayoutColliderUpdate(){
	WayoutCollideResult wayoutCollResult = ColliderManager::GetInstance()->IsCollideWayOut(playerObject->GetAABB());
	if (wayoutCollResult.isCollide) {
		//
		TMX_MAP_TYPE newMapType = GameMapUtil::MapNameToType(wayoutCollResult.wayoutInfo.next_map_name);
		playerObject->SetPositionedMapType(newMapType);
		// repositioning player for new map.
		WayOutToDirection toDir = GameMapUtil::DirNameToEnum(wayoutCollResult.wayoutInfo.toDirection);
		WayOut wayout;
		switch (toDir){
		case WayOutToDirection::NORTH:
			wayout = worldMap->GetWayoutInfo(WayOutToDirection::SOUTH);
			playerObject->SetObjectPosition(wayout.x, wayout.y - 32.0f);
			break;
		case WayOutToDirection::SOUTH:
			wayout = worldMap->GetWayoutInfo(WayOutToDirection::NORTH);
			playerObject->SetObjectPosition(wayout.x, wayout.y + 32.0f);
			break;
		case WayOutToDirection::WEST:
			wayout = worldMap->GetWayoutInfo(WayOutToDirection::EAST);
			playerObject->SetObjectPosition(wayout.x + 32.0f, wayout.y);
			break;
		case WayOutToDirection::EAST:
			wayout = worldMap->GetWayoutInfo(WayOutToDirection::WEST);
			playerObject->SetObjectPosition(wayout.x - 32.0f, wayout.y);
			break;
		default:
			break;
		}
	}
}
