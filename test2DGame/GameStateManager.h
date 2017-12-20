#pragma once
#include "GameState.h"
#include <stack>
using namespace std;

enum GAME_STATE 
{
	MAIN_MENU = 0,
	INGAME = 1
};
class GameStateManager
{
public:
	~GameStateManager();
	static GameStateManager* GetInstance();
	void InsertState(GameState* state);
	void LatePopState();
	GameState* const GetCurrentState();

	bool nextStateFlag = false;
private:
	GameStateManager();
	void PopState();
	stack<GameState*> gamestates;
	static GameStateManager* instance;
	
};

