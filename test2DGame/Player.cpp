#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Draw()
{
	spriteObject->DrawSprite();
}

void Player::Update()
{

}

void Player::SetSpriteObject(Game2DSprite* _spriteObject)
{
	if (_spriteObject != nullptr) spriteObject = _spriteObject;
}

D3DXVECTOR3 Player::GetObjectPostion()
{
	return spriteObject->GetSpritePos();
}

void Player::Move(FLOAT _x, FLOAT _y)
{
	spriteObject->TranslateSprite(_x, _y);
}
