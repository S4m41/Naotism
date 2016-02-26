#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Entity.h"



enum Errors
{
	Fine = 0 , Close = 1 << 0 , Read = 1 << 1 , Write = 1 << 2 , Other = 1 << 2
};

class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	void Game::init();

	void Game::update(double delta);


	bool Game::isRunning()const;
	void Game::problem(Errors error);
	int Game::getErrors() const;
	void operator =( const Game& otherGame );



protected:
	std::vector<Entity*> entitylist;
private:
	virtual void Game::draw(sf::RenderTarget& canvas , sf::RenderStates states)const;
	int error;
	void scarySprite(sf::RenderTarget& canvas)const;//for testing
	int score = 0;
	void clearDead();
	void spawnNew();

};
