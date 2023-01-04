#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow *window)
    :State(window)
{
    this->shape.setFillColor(sf::Color::Red);
}
MainMenuState::~MainMenuState()
{
}

void MainMenuState::updateInput(sf::RenderTarget *target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        settings_ = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        next_ = true;
    }
}
void MainMenuState::update(sf::RenderTarget *target, const float &dt)
{
    updateMousePosition();
    updateInput(target);
    std::cout << "MENU \n";
}
void MainMenuState::render(sf::RenderTarget *target)
{
    target->draw(shape);
}