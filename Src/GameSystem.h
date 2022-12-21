#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#define PI 3.14159265359

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
//#include <X11/extensions/Xrandr.h> Linux

class GameSystem
{

private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::Clock dtClock;
	float dt;

	void initWindow();

public:

	GameSystem();
	virtual ~GameSystem();

	void endApplication();

	void updateDt();
	void updateEvents();

	void update();
	void render();

	void run();

};

#endif