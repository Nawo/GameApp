#include "GameState.h"
sf::CircleShape shape(100.f);
GameState::GameState(sf::RenderWindow *window)
    :State(window)
{
    this->shape.setFillColor(sf::Color::Green);
}
GameState::~GameState()
{
}

// ============== GETTER/SETTER ============== //

// ============== UPDATE ============== //

void GameState::updateInput(sf::RenderTarget *target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        settings_ = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mainMenu_ = true;
    }
}
void GameState::update(sf::RenderTarget *target, const float &dt)
{
    updateMousePosition();
    updateInput(target);
    std::cout << "GAME \n";
}

// ============== RENDER ============== //

void GameState::render(sf::RenderTarget *target)
{
    target->draw(shape);
}