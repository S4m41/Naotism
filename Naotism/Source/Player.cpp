#include "Player.h"
void Player::update(double delta) {
	score += (int) ( delta += 0.5 );
	sf::Vector2f vel = getVelocity();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vel.x -= ( 1 * delta );
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vel.x += ( 1 * delta );
	}

}