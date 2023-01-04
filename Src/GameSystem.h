#pragma once

#include "State.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "SettingsState.h"

class GameSystem
{

private:

	sf::RenderWindow* window_;
	sf::VideoMode videoMode_;
	sf::Event event_;

	sf::Clock dtClock_;
	float dt_;

	std::vector<State*> states_;

	State* statePtr_;

	void initWindow();
	void initStates();

public:

	GameSystem();
	virtual ~GameSystem();

	void updateDt();
	void updateEvents();

	void update();
	void render();

	void run();

};