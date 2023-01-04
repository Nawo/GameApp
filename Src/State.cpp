#include "State.h"

State::State(sf::RenderWindow* window)
	: window_(window) {}
	
State::~State() {}

const bool &State::getQuit() { return quit_; }
const bool &State::getNext() { return next_; }
const bool &State::getSettings() { return settings_; }
const bool &State::getMainMenu() { return mainMenu_; }

void State::setQuit(bool type) { quit_ = type; }
void State::setNext(bool type) { next_ = type; }
void State::setSettings(bool type) { settings_ = type; }
void State::setMainMenu(bool type) { mainMenu_ = type; }

void State::updateMousePosition()
{
	MousePosScreen_ = sf::Mouse::getPosition();
	MousePosWindow_ = sf::Mouse::getPosition(*window_);
	MousePosView_ = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
}