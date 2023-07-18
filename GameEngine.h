#pragma once
#include <string>
using std::string;

class GameEngine {
	enum state {
		start,
		maploaded,
		mapvalidated,
		playersadded,
		assignreforcement,
		issueorders,
		executeorders,
		win,
		end
	};
public:
	GameEngine();
	GameEngine(GameEngine& game);
	~GameEngine();
	string getState();
	void getCommand();
	void invalidCommand();
private:
	state currentState;
	void executeCommand(string command);
	void changeState(state newState);
};