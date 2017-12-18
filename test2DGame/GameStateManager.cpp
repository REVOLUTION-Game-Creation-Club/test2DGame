#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
}


GameStateManager::~GameStateManager()
{
}

void GameStateManager::InsertState(GameState * state)
{
	gamestates.push(state);
}

void GameStateManager::PopState()
{
	gamestates.top()->Release();
	gamestates.pop();
}

GameState* const GameStateManager::GetCurrentState()
{
	return gamestates.top();
}
