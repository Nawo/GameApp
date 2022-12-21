// //////////////////////////////////////////////////
// //
// //				INCLUDE SECTION
// //
// //////////////////////////////////////////////////

#include "GameSystem.h"

// //////////////////////////////////////////////////
// //
// //				CONSTRUCTOR/DESTRUCTOR
// //
// //////////////////////////////////////////////////

GameSystem::GameSystem()
{
	this->initWindow();
}

GameSystem::~GameSystem()
{
	delete this->window;
}

void GameSystem::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void GameSystem::endApplication()
{
	std::cout << "Ending application!" << std::endl;
}

//////////////////////////////////////////////////
//
//				INIT SECTION
//
//////////////////////////////////////////////////

void GameSystem::initWindow()
{

	this->videoMode.size.y = 720;
	this->videoMode.size.x = 1280;

	this->window = new sf::RenderWindow(this->videoMode, "Game projects", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(75);
	this->window->setVerticalSyncEnabled(true);
	this->window->setMouseCursorVisible(false);
}

//////////////////////////////////////////////////
//
//				UPDATE SECTION
//
//////////////////////////////////////////////////

void GameSystem::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void GameSystem::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void GameSystem::update()
{
	this->updateDt();
	this->updateEvents();
}

//////////////////////////////////////////////////
//
//				 RENDER SECTION
//
//////////////////////////////////////////////////

void GameSystem::render()
{

	this->window->clear();

	this->window->display();
}