#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <map>
#include <math.h>
#include <random>
#include <sstream>

class State
{
private:

protected:
    bool quit_ = false;
    bool next_ = false;
    bool settings_ = false;
    bool mainMenu_ = false;

public:
    State(sf::RenderWindow *window);
    virtual ~State();

    sf::RenderWindow *window_;

    sf::Vector2i MousePosScreen_;
    sf::Vector2i MousePosWindow_;
    sf::Vector2f MousePosView_;

    void updateMousePosition();

    virtual const bool &getQuit();
    virtual const bool &getNext();
    virtual const bool &getSettings();
    virtual const bool &getMainMenu();

    virtual void setQuit(bool type);
    virtual void setNext(bool type);
    virtual void setSettings(bool type);
    virtual void setMainMenu(bool type);

    virtual void updateInput(sf::RenderTarget *target) = 0;
    virtual void update(sf::RenderTarget *target, const float &dt) = 0;
    virtual void render(sf::RenderTarget *target) = 0;
};