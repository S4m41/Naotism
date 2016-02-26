#include "Player.h"
Player::Player(float x , float y , sf::Vector2f velocity , int mass) : Collidable(x , y , velocity , mass) {
}
Player::Player(const Player* /*&*/other) : Collidable(other) {
}
void Player::update(double delta) {


	sf::Vector2f vel = getVelocity();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		direction.x = -1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		direction.x = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		//direction.y = -1;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		direction.x = 0;
		//vel.x *= .5;
	}

	vel.x = speed.x * direction.x * delta;
	vel.y = speed.y * direction.y * delta;
	setVelocity(vel);
	Collidable::update(delta);
}
const sf::Vector2i Player::getType()const {
	return this->texture_strct.PLAYER;
}
Player* Player::clone()const {
	return new Player(this);
}
void Player::collide(const Collidable*& other) {
	remove_me = true;
}