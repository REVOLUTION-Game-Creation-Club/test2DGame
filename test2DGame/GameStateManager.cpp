#include "GameStateManager.h"

GameStateManager* GameStateManager::instance = nullptr;

GameStateManager::GameStateManager()
{

}


GameStateManager::~GameStateManager()
{
}

GameStateManager * GameStateManager::GetInstance()
{
	if (instance == nullptr) instance = new GameStateManager();
	return instance;
}

void GameStateManager::InsertState(GameState * state)
{
	gamestates.push(state);
}

void GameStateManager::LatePopState()
{
	if (nextStateFlag)
	{
		PopState();
		nextStateFlag = false;
	}
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
