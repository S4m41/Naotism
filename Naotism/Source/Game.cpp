#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"//noo don't
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