#pragma once
#include <string>
using std::string;

class GameEngine {
	enum states {
		start,
		maploaded,
		mapvalidated,
		palyersadded,
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
	void setState();
	void getCommand();
private:
	states currentState;
	void changeState();
};