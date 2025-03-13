#include "stdafx.h"
#include "Game.h"
#include "crtdbg.h"
#include "GameStates/StateMachine.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game game;

	game.Run();

	return 0;
}
