//////////////////////////////////////////////////
//
//				INCLUDE SECTION
//
//////////////////////////////////////////////////

#include "GameSystem.h"

//////////////////////////////////////////////////
//
//				CONSTRUCTOR/DESTRUCTOR
//
//////////////////////////////////////////////////

GameSystem::GameSystem()
{
	initWindow();
	initStates();
}

GameSystem::~GameSystem()
{
	delete window_;
}

//////////////////////////////////////////////////
//
//				IMPORTANT FUNCTIONS
//
//////////////////////////////////////////////////

void GameSystem::run()
{
	while (window_->isOpen())
	{
		update();
		render();
	}
}

//////////////////////////////////////////////////
//
//				INIT SECTION
//
//////////////////////////////////////////////////

void GameSystem::initWindow()
{

	videoMode_.size.y = 720;
	videoMode_.size.x = 1280;

	window_ = new sf::RenderWindow(videoMode_, "Game project", sf::Style::Titlebar | sf::Style::Close);

	window_->setFramerateLimit(75);
	window_->setVerticalSyncEnabled(true);
	window_->setMouseCursorVisible(false);
}

void GameSystem::initStates()
{

	states_.emplace_back(new MainMenuState(window_));
	states_.emplace_back(new SettingsState(window_));
	states_.emplace_back(new GameState(window_));

	statePtr_ = states_.back();

}

//////////////////////////////////////////////////
//
//				UPDATE SECTION
//
//////////////////////////////////////////////////

void GameSystem::updateDt()
{
	dt_ = dtClock_.restart().asSeconds();
}

void GameSystem::updateEvents()
{
	while (window_->pollEvent(event_))
	{
		if (event_.type == sf::Event::Closed)
		{
			window_->close();
		}
	}
}

void GameSystem::update()
{
	updateDt();
	updateEvents();
	if (!states_.empty())
	{
		statePtr_->update(window_, dt_);

		if (statePtr_->getQuit())
		{
			statePtr_->setQuit(false);
			statePtr_ = states_[2];
		}
		else if (statePtr_->getNext())
		{
			statePtr_->setNext(false);
			statePtr_ = states_[2];
		}
		else if (statePtr_->getSettings())
		{
			statePtr_->setSettings(false);
			statePtr_ = states_[0];
		}
		else if (statePtr_->getMainMenu())
		{
			statePtr_->setMainMenu(false);
			statePtr_ = states_[1];
		}
	}
	else
	{
		window_->close();
	}
}

//////////////////////////////////////////////////
//
//				 RENDER SECTION
//
//////////////////////////////////////////////////

void GameSystem::render()
{

	window_->clear();

	if (!states_.empty())
		//states_.back()->render(window_);
		statePtr_->render(window_);

	window_->display();
}