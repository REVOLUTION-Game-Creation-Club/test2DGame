#pragma once
#include "GameState.h"
#include <stack>
using namespace std;

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();

	void InsertState(GameState* state);
	GameState* GetCurrentState();
private:
	stack<GameState*> gamestates;
};

