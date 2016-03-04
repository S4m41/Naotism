#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include "Engine.h"//noo don't
#define IMMORTAL 0
int unsigned_to_signed(unsigned n) throw( ... );
Game::Game() {
	error = Errors::Fine;
}
Game::~Game() {
	entitylist.clear();
}
void Game::init() {

	//Entity* ent_ptr = new Enemy(1);
	if(!font.loadFromFile("Resources/GARA.ttf")) {
		std::cout << "font not found" << std::endl;
		error = error | Errors::Read;
		getchar();
	}
	scoretxt.setFont(font);
	scoretxt.setCharacterSize(24);
	scoretxt.setColor(sf::Color::Cyan);
	Entity* ent_ptr = new Player();
	try {
		ent_ptr->init();
	} catch(int i) {
		if(i == -12) {
			std::cout << "Image not found" << std::endl;
		}
		error = error | Errors::Read;
	}

	this->entitylist.push_back(ent_ptr);
}
//################################################
void Game::update(float delta) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		problem(Close);
	}
	if(!GAMEOVER.gameover) {
		score += 1 + (int) (1+ delta + 0.5 );
		scoretxt.setString(std::to_string(score));

		for ( int i = 0; i < entitylist.size();i++ ) {
			Entity* var =entitylist.at(i);
			var->update(delta);
		}
		handleCollisions();
		spawnNew(delta);
		clearDead();
		//std::cout << "|";
	} else {
		std::string s = ( " you scored :" + std::to_string(score) );
		s += "\nGAME OVER! Press n to start anew";
		scoretxt.setString(s);
		GAMEOVER.ttcooldown += 1;
		if(GAMEOVER.ttcooldown > GAMEOVER.cooldown) {
			GAMEOVER.ttcooldown = 0;
			scoretxt.setColor(sf::Color(rand() % 256 , rand() % 256 , rand() % 256));
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
			score = 0;
			GAMEOVER.gameover = false;
			clear();
			init();
		}
	}
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void Game::draw(sf::RenderTarget& canvas , sf::RenderStates states)const {
	for(int i = 0; i < entitylist.size(); i++) {
		Entity* var = entitylist.at(i);
		canvas.draw(*var);
	}
	canvas.draw(scoretxt);


	//scarySprite(canvas);
}
//################################################
bool Game::isRunning() const {
	return ( !( Fine^error ) );
}
void Game::problem(Errors ErrorCode) {
	error = error | ErrorCode;
}
int Game::getErrors() const {
	return error;
}
void Game::operator =( const Game& otherGame ) {
	this->error = otherGame.error;
}
void Game::spawnNew(float delta) {
	double d = bell(score , 500) , e = bell(score , 1500) , f = bell(score , 2500) , g = bell(score , 3500);
	if(rand() % 100 < d*delta) {

		Entity* ent_ptr = new Enemy(ENEMY_TYPES::TOWEL , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % 100 < e *delta) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::ROCK , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % 100 < f *delta) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::SPACESHIP , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % 100 < g *delta) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::A_BOMB , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(score > 4000 && rand() % 100 < 50 * delta) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::A_BOMB , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
}

void Game::clearDead() {
	for(int i = 0; i < entitylist.size(); i++) {
		Entity* var = entitylist.at(i);
		if(var->isDead()) {
			Player* t1 = dynamic_cast<Player*>( var );
			if(t1) {
				//game over
#if !IMMORTAL
				std::cout << "GAME OVER" << std::endl;
				GAMEOVER.gameover = true;
#endif
			} else
				std::cout << "@Entity removed@" << std::endl;
			entitylist.erase(i);
			i--;
		}
	}
	
}
int unsigned_to_signed(unsigned n) {
	if(n <= INT_MAX)
		return static_cast<int>( n );

	if(n >= INT_MIN)
		return static_cast<int>( n - INT_MIN ) + INT_MIN;

	throw - 3;
}
void Game::handleCollisions()  {
	for(int i = 0; i < entitylist.size();i++) {
		Entity* var = entitylist.at(i);
		Collidable* coll = dynamic_cast<Collidable*>( var );
		if(coll) {
			for  ( int j = 0; j < entitylist.size();j++ ) {
				Entity* var1 = entitylist.at(j);
				Collidable* coll1 = dynamic_cast<Collidable*>( var1 );
				if(var1) {
					if(coll->isColliding(coll1))
						coll->collide(coll1);
				}
			}
		}
	}
}
void Game::clear() {
	entitylist.clear();
}