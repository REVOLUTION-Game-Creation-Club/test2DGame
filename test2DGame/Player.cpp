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