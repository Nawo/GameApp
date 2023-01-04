#include "SettingsState.h"

SettingsState::SettingsState(sf::RenderWindow *window)
    :State(window)
{
    this->shape.setFillColor(sf::Color::Blue);
    
}
SettingsState::~SettingsState()
{
    
}

void SettingsState::updateInput(sf::RenderTarget *target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        quit_ = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mainMenu_ = true;
    }
}
void SettingsState::update(sf::RenderTarget *target, const float &dt)
{
    updateMousePosition();
    updateInput(target);
    std::cout << "SETTINGS \n";
}
void SettingsState::render(sf::RenderTarget *target)
{
    target->draw(shape);
}