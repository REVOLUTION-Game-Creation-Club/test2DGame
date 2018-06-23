#include "Player.h"


Player::Player(){
}


Player::~Player(){
	delete spriteObject;
}

void Player::Update(){
	// draw sprite
	spriteObject->DrawSprite();
	// animaiton playing.
	animation.Update();
}

void Player::Init(Game2DSprite * _spriteObject){
	if (_spriteObject != nullptr) spriteObject = _spriteObject;
	// init animation.
	animation.SetSpriteObject(spriteObject);
	DrawInfo forward = { 96, 128, 0, 32, 0, 0, 32, 300 };
	DrawInfo left = { 96, 128, 32, 64, 0, 0, 32, 300 };
	DrawInfo right = { 96, 128, 64, 96, 0, 0, 32, 300 };
	DrawInfo back = { 96, 128, 96, 128, 0, 0, 32, 300 };
	animation.SetDrawInfos(FourDirDrawInfo(left, right, back, forward));
	// defualt direction setting.
	curLookDir = LOOK_DIRECTION::forward;
	animation.SetLookDir(LOOK_DIRECTION::forward);
}

D3DXVECTOR3 Player::GetObjectPosition(){
	return spriteObject->GetSpritePos();
}

void Player::SetObjectPosition(FLOAT x, FLOAT y) {
	spriteObject->SetSpritePos(D3DXVECTOR3(x, y, 0.0f));
	UpdateAABB();
}
void Player::SetObjectPosition(D3DXVECTOR3 vec) {
	spriteObject->SetSpritePos(vec);
	UpdateAABB();
}

void Player::Move(FLOAT _x, FLOAT _y){
	spriteObject->TranslateSprite(_x, _y);
	UpdateAABB();
}
void Player::Move(D3DXVECTOR3 vec) {
	spriteObject->TranslateSprite(vec.x, vec.y);
	UpdateAABB();
}
Box2DCollider Player::GetAABB(){
	return box2DColl;
}

void Player::SetLookDirection(LOOK_DIRECTION _lookDir){
	curLookDir = _lookDir;
	animation.SetLookDir(_lookDir);
}

void Player::SetPositionedMapType(TMX_MAP_TYPE curMapType){
	curPositionedMapType = curMapType;
}

TMX_MAP_TYPE Player::GetCurMapType(){
	return curPositionedMapType;
}

void Player::UpdateAABB(){
	// make aabb
	box2DColl.MakeAABB(D3DXVECTOR3(spriteObject->GetSpritePos()),
		D3DXVECTOR3(spriteObject->GetSpritePos().x + 32.0f,
			spriteObject->GetSpritePos().y + 32.0f, 0.0f));
}


