#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include "InGameState.h"
#include "KojeomD3DUtil.h"
#include <stack>
using namespace std;

enum class GAME_STATE 
{
	NONE,
	MAIN_MENU,
	INGAME
};
class GameStateManager
{
public:
	~GameStateManager();
	static GameStateManager* GetInstance();
	void InsertState(GAME_STATE stateType);
	void PopState();
	GameState* GetCurrentState();
private:
	GameStateManager();
	
	stack<GameState*> gamestates;
	static GameStateManager* instance;

	GameState* mainmenuState;
	GameState* ingameState;
};

