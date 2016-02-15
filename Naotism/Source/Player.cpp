#include "Player.h"
Player::Player(int i ,float x , float y , sf::Vector2f velocity , int mass) : Collidable(x , y , velocity , mass), score(0) {}
void Player::update(double delta) {
	score += (int) ( delta += 0.5 );
	sf::Vector2f vel = getVelocity();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vel.x -= ( 1 * delta );
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vel.x += ( 1 * delta );
	}

}
const sf::Vector2i Player::getType()const {
	return this->texture_strct.PLAYER;
}