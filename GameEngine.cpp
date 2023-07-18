#include "GameEngine.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

GameEngine::GameEngine()
{
	this->currentState = start;
}

GameEngine::GameEngine(GameEngine& game)
{
	this->currentState = game.currentState;
}

GameEngine::~GameEngine()
{
}

string GameEngine::getState()
{
	switch (this->currentState)
	{
	case start:
		return "start";
	case maploaded:
		return "map loaded";
	case mapvalidated:
		return "map validated";
	case playersadded:
		return "players added";
	case assignreforcement:
		return "assigning reinforcement";
	case issueorders:
		return "issuing orders";
	case executeorders:
		return "executing orders";
	case win:
		return "game won";
	case end:
		return "game ended";
	default:
		return "invalid state";
	}
}

void GameEngine::getCommand()
{
	string command;
	cout << endl << "Please enter a command: ";
	cin >> command;
	this->executeCommand(command);
}

void GameEngine::executeCommand(string command)
{
	switch (this->currentState)
	{
	case start:
		if (command == "loadmap")
			changeState(maploaded);
		else
			this->invalidCommand();
		break;
	case maploaded:
		if (command == "loadmap")
			changeState(maploaded);
		else if (command == "validatemap")
			changeState(mapvalidated);
		else
			this->invalidCommand();
		break;
	case mapvalidated:
		if (command == "addplayer")
			changeState(playersadded);
		else
			this->invalidCommand();
		break;
	case playersadded:
		if (command == "addplayer")
			changeState(playersadded);
		else if (command == "assigncountries")
			changeState(assignreforcement);
		else
			this->invalidCommand();
		break;
	case assignreforcement:
		if (command == "issueorder")
			changeState(issueorders);
		else
			this->invalidCommand();
		break;
	case issueorders:
		if (command == "issueorder")
			changeState(issueorders);
		else if (command == "endissueorders")
			changeState(executeorders);
		else
			this->invalidCommand();
		break;
	case executeorders:
		if (command == "exeorder")
			changeState(executeorders);
		else if (command == "endexeorders")
			changeState(assignreforcement);
		else if (command == "win")
			changeState(win);
		else
			this->invalidCommand();
		break;
	case win:
		if (command == "end")
			changeState(end);
		else if (command == "play")
			changeState(start);
		else
			this->invalidCommand();
		break;
	default:
		this->invalidCommand();
	}
}

void GameEngine::invalidCommand() {
	cout << "Invalid command." << endl;
	cout << "Current game state: " << this->getState() << endl;
	cout << "Available commands: ";
	switch (this->currentState)
	{
	case start:
		cout << "loadmap" << endl;
		break;
	case maploaded:
		cout << "loadmap, validatemap" << endl;
		break;
	case mapvalidated:
		cout << "addplayer" << endl;
		break;
	case playersadded:
		cout << "addplayer, assigncountries" << endl;
		break;
	case assignreforcement:
		cout << "issueorder" << endl;
		break;
	case issueorders:
		cout << "issueorder, endissueorders" << endl;
		break;
	case executeorders:
		cout << "exeorder, endexeorders, win" << endl;
		break;
	case win:
		cout << "play, end" << endl;
		break;
	default:
		cout << endl;
	}
}

void GameEngine::changeState(state newState)
{
	this->currentState = newState;
	cout << "Game state changed to: " << this->getState() << endl;
}
