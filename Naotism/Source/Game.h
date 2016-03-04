#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "Vector.h"



enum Errors
{
	Fine = 0 , Close = 1 << 0 , Read = 1 << 1 , Write = 1 << 2 , Other = 1 << 2
};

class Game : public sf::Drawable
{
public:
	Game();
	virtual ~Game();

	void Game::init();

	void Game::update(float delta);


	bool Game::isRunning()const;
	void Game::problem(Errors error);
	int Game::getErrors() const;
	void operator =( const Game& otherGame );

	void clear();

protected:

	Vector_E entitylist;
private:
	int error;
	int score = 0;
	sf::Font font;
	sf::Text scoretxt;

	typedef struct _go{
		bool gameover = false;
		const int cooldown = 2;
		int ttcooldown;
	}GOStat;
	GOStat GAMEOVER;

	virtual void Game::draw(sf::RenderTarget& canvas , sf::RenderStates states)const;
	void Game::clearDead();
	void Game::spawnNew(float delta);
	void Game::handleCollisions() ;

	void Game::scarySprite(sf::RenderTarget& canvas)const;//for testing




};
