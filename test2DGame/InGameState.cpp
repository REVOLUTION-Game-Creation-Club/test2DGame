#include "InGameState.h"



InGameState::InGameState()
{
}


InGameState::~InGameState()
{
}

void InGameState::Init(IDirect3DDevice9 * _d3dDevice)
{
	playerFactory = new PlayerFactory();
	playerObject = playerFactory->ProduceGameObject(GAMEOBJECT_TYPE::PLAYER);
	playerSprite = new Player2DSprite();
	playerSprite->Init(_d3dDevice, FilePath::GetInstance()->chacracter01, RECT { 0, 0, 32, 42 },
		384, 256);
	playerObject->SetSpriteObject(playerSprite);

	// player offset 위치 적용.
	// - view 크기의 정중앙값을 offset으로 사용.
	playerObject->Move(Simple2DCamera::GetInstance()->GetViewWidth() / 2 + 150.0f ,
		Simple2DCamera::GetInstance()->GetViewHeight() / 2);

	playerTestAni.SetSpriteObject(playerSprite);
	playerTestAni.SetDrawInfos(DrawInfo{ 96, 128, 0, 32, 0, 0, 32, 200 });

	worldMap = new WorldMap(_d3dDevice);

	playerObject->GetAABB()->MakeAABB(D3DXVECTOR3(playerObject->GetObjectPosition()),
		D3DXVECTOR3(playerObject->GetObjectPosition().x + 32.0f,
			playerObject->GetObjectPosition().y + 32.0f, 0.0f));
}

void InGameState::Update()
{
	worldMap->Update(); // order : 0
	playerObject->Update(); // order : 1
	playerTestAni.DrawFrames();

	playerObject->GetAABB()->MakeAABB(D3DXVECTOR3(playerObject->GetObjectPosition()),
		D3DXVECTOR3(playerObject->GetObjectPosition().x + 32.0f,
			playerObject->GetObjectPosition().y + 32.0f, 0.0f));
}

void InGameState::Release()
{
	delete worldMap;
	delete playerObject;
	delete playerFactory;
}

void InGameState::InputUpdate(UINT msg, WPARAM wParam)
{
	float moveX = 0.0f, moveY = 0.0f;
	switch (msg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			moveX = -32.0f;
			moveY = 0.0f;
		}
		else if (wParam == VK_RIGHT)
		{
			moveX = 32.0f;
			moveY = 0.0f;
		}
		else if (wParam == VK_UP)
		{
			moveX = 0.0f;
			moveY = -32.0f;
		}
		else if (wParam == VK_DOWN)
		{
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
