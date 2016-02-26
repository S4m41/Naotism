#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"//noo don't
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
void Game::update(double delta) {
	score += 1 + (int) ( 1 / delta + 0.5 );
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		problem(Close);
	}
	for each ( Entity* var in entitylist ) {
		var->update(delta);
	}
	spawnNew();
	clearDead();
	std::cout << "|";
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void Game::draw(sf::RenderTarget& canvas , sf::RenderStates states)const {
	for each ( Entity* var in entitylist ) {
		canvas.draw(*var);
	}
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
	if(rand() % score > 100) {
		Entity* ent_ptr = new Enemy(ENEMY_TYPES::ROCK , rand() % SCREENSIZES::LARGE.x , 0);
		ent_ptr->init();
		entitylist.push_back(ent_ptr);
	}
	if(rand() % score > 1e7) {

	}
	if(rand() % score > 1e9) {

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
				std::cout << "GAME OVER" << std::endl;
				getchar();//print to sfml not console
				problem(Errors::Other);//clarify
			}
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