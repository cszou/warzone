#include "GameEngineDriver.h"
#include "GameEngine.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void testGameStates() {
	cout << endl << "********** Part 5: Game Engine **********" << endl;
	GameEngine* game = new GameEngine();
	cout << "Current game state: " << game->getState() << endl;
	while (game->getState() != "game ended")
		game->getCommand();
}