#include "InGameState.h"



InGameState::InGameState()
{
}


InGameState::~InGameState()
{
	delete worldMap;
	delete playerObject;
	delete playerFactory;
}

void InGameState::Init(IDirect3DDevice9 * _d3dDevice)
{
	isStarted = false;
	playerFactory = new PlayerFactory();
	playerObject = playerFactory->ProduceGameObject(GAMEOBJECT_TYPE::PLAYER);
	playerSprite = new Player2DSprite();
	playerSprite->Init(_d3dDevice, FilePath::GetInstance()->chacracter01, RECT { 0, 0, 32, 32 },
		96, 128);
	playerObject->Init(playerSprite);

	// player offset 위치 적용.
	// - view 크기의 정중앙값을 offset으로 사용.
	// 임시로 96.0f를 x 값에 더하여 위치를 정한다. ( 테스트용.)
	playerObject->Move(Simple2DCamera::GetInstance()->GetViewWidth() / 2 + 96.0f ,
		Simple2DCamera::GetInstance()->GetViewHeight() / 2);

	worldMap = new WorldMap(_d3dDevice);
	//test 임시 코드.
	ColliderManager::GetInstance()->SetCurrentMapType(TMX_MAP_TYPE::MAIN_TOWN);
}

void InGameState::Start()
{
	if (isStarted) return;
	isStarted = true;

}

void InGameState::Update()
{
	worldMap->Update(); // order : 0
	playerObject->Update(); // order : 1
}

void InGameState::Release()
{
	isStarted = false;
}

void InGameState::InputUpdate(UINT msg, WPARAM wParam)
{
	float moveX = 0.0f, moveY = 0.0f;
	switch (msg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			playerObject->SetLookDirection(LOOK_DIRECTION::left);
			moveX = -32.0f;
			moveY = 0.0f;
		}
		else if (wParam == VK_RIGHT)
		{
			playerObject->SetLookDirection(LOOK_DIRECTION::right);
			moveX = 32.0f;
			moveY = 0.0f;
		}
		else if (wParam == VK_UP)
		{
			playerObject->SetLookDirection(LOOK_DIRECTION::back);
			moveX = 0.0f;
			moveY = -32.0f;
		}
		else if (wParam == VK_DOWN)
		{
			playerObject->SetLookDirection(LOOK_DIRECTION::forward);
			moveX = 0.0f;
			moveY = 32.0f;
		}

		// test code...
		Box2DCollider intersectTest;
		D3DXVECTOR3 min = playerObject->GetAABB()->GetMinExtent();
		D3DXVECTOR3 max = playerObject->GetAABB()->GetMaxExtent();
		intersectTest.MakeAABB(D3DXVECTOR3(min.x + moveX, min.y + moveY, 0.0f),
			D3DXVECTOR3(max.x + moveX, max.y + moveY, 0.0f));
		if (ColliderManager::GetInstance()->
			IsCollideWithMapObject(intersectTest) == false)
		{
			playerObject->Move(moveX, moveY);
			Simple2DCamera::GetInstance()->FollowPlayer(-moveX, -moveY);
		}
		// test code...
		break;
	}
}
