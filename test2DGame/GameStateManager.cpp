#include "GameStateManager.h"

GameStateManager* GameStateManager::instance = nullptr;

GameStateManager::GameStateManager()
{
	ingameState = new InGameState();
	mainmenuState = new MainMenuState();

	ingameState->Init(KojeomD3DUtil::GetInstance()->GetD3DDevice());
	mainmenuState->Init(KojeomD3DUtil::GetInstance()->GetD3DDevice());
}


GameStateManager::~GameStateManager()
{
}

GameStateManager * GameStateManager::GetInstance()
{
	if (instance == nullptr) instance = new GameStateManager();
	return instance;
}

void GameStateManager::InsertState(GAME_STATE stateType)
{
	switch (stateType) {
	case GAME_STATE::INGAME:
		gamestates.push(ingameState);
		break;
	case GAME_STATE::MAIN_MENU:
		gamestates.push(mainmenuState);
		break;
	case GAME_STATE::NONE:
		// none..
		break;
	}
}


void GameStateManager::PopState()
{
	gamestates.top()->Release();
	gamestates.pop();
}

GameState* const GameStateManager::GetCurrentState()
{
	if(gamestates.size() > 0) return gamestates.top();
	else return nullptr;
	
}
