#pragma once

#include "State.h"

class SettingsState : public State
{

private:
    std::map<std::string, sf::Texture> textures;

    sf::RectangleShape shape;

public:
    SettingsState(sf::RenderWindow *window);
    virtual ~SettingsState();

    void updateInput(sf::RenderTarget *target) override;
    void update(sf::RenderTarget *target, const float &dt) override;
    void render(sf::RenderTarget *target) override;
};