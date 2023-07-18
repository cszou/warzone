#include "MapDriver.h"
#include "PlayerDriver.h"
#include "OrdersDriver.h"
#include "CardsDriver.h"
#include "GameEngineDriver.h"
//#include "TournamentDriver.h"
//#include "PlayerStrategiesDriver.h"
#include <iostream>
using std::cout;
using std::endl;
#include <time.h>

int main() {
	testLoadMaps();
	testPlayer();
	testOrdersList();
	testCards();
	testGameStates();
	/*cout << "\n************* Part 1: Player Strategy *************" << endl;
	testPlayerStrategies();*/
	/*cout << "\n************* Part 2: Tournament Mode *************" << endl;
	testTournament();*/
}
