#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
double bell(int tick , int i , int max = 5);
Game::Game() {
	error = Errors::Fine;
}
Game::~Game() {
	entitylist.clear();
}
void Game::init() {
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
void Game::update(float delta) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		problem(Close);
	}
	if(!GAMEOVER.gameover) {
		score += 1 + (int) ( 1 + delta + 0.5 );
		scoretxt.setString(std::to_string(score));

		for(int i = 0; i < entitylist.size(); i++) {
			Entity* var = entitylist.at(i);
			var->update(delta);
		}
		handleCollisions();
		spawnNew(delta);
		clearDead();
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
			//rensa alla entities i listan
			entitylist.clear();
			//initiera om game
			init();
		}
	}
}
void Game::draw(sf::RenderTarget& canvas , sf::RenderStates states)const {
	for(int i = 0; i < entitylist.size(); i++) {
		Entity* var = entitylist.at(i);
		canvas.draw(*var);
	}
	canvas.draw(scoretxt);
}
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
	double d = bell(score , 500) , e = bell(score , 1500) , f = bell(score , 2500) , g = bell(score , 3500),match = rand() % 100;
	Entity* ent_ptr = nullptr;

	if(match< d*delta) {
		ent_ptr = new Enemy(ENEMY_TYPES::TOWEL , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
	}else if(match< e *delta) {
		 ent_ptr = new Enemy(ENEMY_TYPES::ROCK , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
	}else if(match< f *delta) {
		ent_ptr = new Enemy(ENEMY_TYPES::SPACESHIP , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
	}else if(match< g *delta || ( score > 4000 && match < 50 * delta )) {
		ent_ptr = new Enemy(ENEMY_TYPES::A_BOMB , (float) ( rand() % SCREENSIZES::screensize_bad.x ) , 0);
	}

	if(ent_ptr) {
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
				std::cout << "GAME OVER" << std::endl;
				GAMEOVER.gameover = true;
			} else {
				std::cout << "@Entity removed@" << std::endl;
				entitylist.erase(i);
				i--;
			}
		}
	}
}
void Game::handleCollisions() {
	for(int i = 0; i < entitylist.size(); i++) {
		/*Collidable* coll = dynamic_cast<Collidable*>( entitylist.at(i) );*/
		Player* coll = dynamic_cast<Player*>( entitylist.at(i) );
		for(int j = 0; coll && j < entitylist.size(); j++) {
			Collidable* coll1 = dynamic_cast<Collidable*>( entitylist.at(j) );
			if(coll1 && coll->isColliding(coll1)) {
				coll->collide(coll1);
			}
		}
	}
}
double bell(int tick , int i/*peak*/ , int max) {
	const double c = pow(3 * 225 , 2);//bell width
	return ( max * exp(-( pow(tick - i , 2) / c )) );
}