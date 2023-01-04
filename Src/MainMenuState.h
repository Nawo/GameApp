#pragma once

#include "State.h"

class MainMenuState : public State
{
private:
    std::vector<sf::Texture> textures;

    sf::RectangleShape shape;

public:
    MainMenuState(sf::RenderWindow *window);
    virtual ~MainMenuState();

    void updateInput(sf::RenderTarget *target) override;
    void update(sf::RenderTarget *target, const float &dt) override;
    void render(sf::RenderTarget *target) override;
};