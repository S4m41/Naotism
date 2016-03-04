#pragma once

#include "SFML\Graphics.hpp"
#include "Util.h"
#include "Game.h"

namespace SCREENSIZES{//should be enum // global var not good
	const sf::Vector2i FULLSCREEN = sf::Vector2i(1900 , 1000);
	const sf::Vector2i LARGE = sf::Vector2i(1520 , 800);
	const sf::Vector2i MEDIUM = sf::Vector2i(950 , 500);
	const sf::Vector2i SMALL = sf::Vector2i(190 , 100); 

	//noo dont do this it is  not good style
	const sf::Vector2i screensize_bad = LARGE;
}

class Engine{
	
public:
	Engine();
	
	virtual ~Engine();


	void Engine::init();
	void Engine::init(Game* currGame);
	void Engine::main_loop();

	void operator =( const Engine& otherEngine );

private:
	
	void handleWindowEvents();
	void fpsCount(long double updatelength);

	long double lastFpsTime;
	int fps;
	const int TARGET_FPS = 64;//MAX 500

	Game* myGame;

	sf::RenderWindow window;

	sf::Vector2i screensize = SCREENSIZES::screensize_bad;
	
};
/*enum sf::vector2i screensizes{
	FULLSCREEN = sf::Vector2i(1900 , 1000);
	LARGE = sf::Vector2i(1520 , 800);
	MEDIUM = sf::Vector2i(950 , 500);
	SMALL = sf::Vector2i(190 , 100); 
}



*/