#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"//noo don't
#define IMMORTAL 0
int unsigned_to_signed(unsigned n) throw( ... );
Game::Game() {
	error = Errors::Fine;
}
Game::~Game() {
	for each ( Entity* var in entitylist ) {
		delete var;
	}
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
		score += 1 + (int) ( 1 / delta + 0.5 );
		scoretxt.setString(std::to_string(score));

		for each ( Entity* var in entitylist ) {
			var->update(delta);
		}
		handleCollisions();
		spawnNew();
		clearDead();
		std::cout << "|";
	} else {
		scoretxt.setString("GAME OVER");
		GAMEOVER.ttcooldown += 1;
		if(GAMEOVER.ttcooldown > GAMEOVER.cooldown) {
			GAMEOVER.ttcooldown = 0;
			scoretxt.setColor(sf::Color(rand() % 256 , rand() % 256 , rand() % 256));
		}
	}
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void Game::draw(sf::RenderTarget& canvas , sf::RenderStates states)const {
	for each ( Entity* var in entitylist ) {
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
void Game::spawnNew() {
	double d = bell(score , 500) , e = bell(score , 1000) , f = bell(score , 1500) , g = bell(score , 2000);
	if(rand() % 100 < d) {

		Entity* ent_ptr = new Enemy(ENEMY_TYPES::TOWEL , (float)(rand() % SCREENSIZES::LARGE.x) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % 100 < e) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::ROCK , (float) ( rand() % SCREENSIZES::LARGE.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % 100 < f) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::SPACESHIP , (float) ( rand() % SCREENSIZES::LARGE.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % 100 < g) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::A_BOMB , (float) ( rand() % SCREENSIZES::LARGE.x ) , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
}
//DOUBT
void Game::clearDead() {
	std::vector<int> removelist_index;
	for(int i = 0; i < unsigned_to_signed(entitylist.size()); i++) {//DOUBT
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
				removelist_index.push_back(i);
		}
	}
	for(int i = 0; i < unsigned_to_signed(removelist_index.size()); i++) {//DOUBT
		Entity* ent_ptr = entitylist.at(removelist_index.at(i));
		entitylist.erase(entitylist.begin() + removelist_index.at(i));
		delete ent_ptr;
	}
}
int unsigned_to_signed(unsigned n) {
	if(n <= INT_MAX)
		return static_cast<int>( n );

	if(n >= INT_MIN)
		return static_cast<int>( n - INT_MIN ) + INT_MIN;

	throw n; // Or whatever else you like
}
void Game::handleCollisions() const {
	for each ( Entity* var in entitylist ) {
		Collidable* coll = dynamic_cast<Collidable*>( var );
		if(coll) {
			for each ( Entity* var1 in entitylist ) {
				Collidable* coll1 = dynamic_cast<Collidable*>( var1 );
				if(var1) {
					if(coll->isColliding(coll1))
						coll->collide(coll1);
				}
			}
		}
	}
}