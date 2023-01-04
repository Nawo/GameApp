#pragma once

#include "State.h"

class GameState : public State
{
private:
    //std::map<std::string, sf::Texture> textures;

    sf::RectangleShape shape;

public:
    GameState(sf::RenderWindow *window);
    virtual ~GameState();

    void updateInput(sf::RenderTarget *target) override;
    void update(sf::RenderTarget *target, const float &dt) override;
    void render(sf::RenderTarget *target) override;
};