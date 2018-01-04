#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	delete spriteObject;
}

void Player::Update()
{
	spriteObject->DrawSprite();
}

void Player::SetSpriteObject(Game2DSprite* _spriteObject)
{
	if (_spriteObject != nullptr) spriteObject = _spriteObject;
}

D3DXVECTOR3 Player::GetObjectPosition()
{
	return spriteObject->GetSpritePos();
}

void Player::Move(FLOAT _x, FLOAT _y)
{
	spriteObject->TranslateSprite(_x, _y);
	box2DColl.MakeAABB(
		D3DXVECTOR3(box2DColl.GetMinExtent().x + _x, box2DColl.GetMinExtent().y + _y, 0.0f),
		D3DXVECTOR3(box2DColl.GetMaxExtent().x + _x, box2DColl.GetMaxExtent().y + _y, 0.0f));
}

Box2DCollider* Player::GetAABB()
{
	return &box2DColl;
}

