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

	void Game::update(float delta);


	bool Game::isRunning()const;
	void Game::problem(Errors error);
	int Game::getErrors() const;
	void operator =( const Game& otherGame );

	void clear();

protected:
	std::vector<Entity*> entitylist;
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
	void Game::spawnNew();
	void Game::handleCollisions() const;

	void Game::scarySprite(sf::RenderTarget& canvas)const;//for testing




};
