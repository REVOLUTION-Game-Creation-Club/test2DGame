#pragma once

class GameState
{
public:
	virtual void Init(IDirect3DDevice9* _d3dDevice) = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;
	virtual ~GameState() {};
};