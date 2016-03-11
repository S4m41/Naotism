#include "Player.h"
#include "Enemy.h"
void Player::update(float delta) {
	sf::Vector2f vel = getVelocity();
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		direction.x = -1;
		this->setScale(1 , 1);

	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		direction.x = 1;
		this->setScale(-1 , 1);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		direction.x = 0;
	}


	vel.x = speed.x * direction.x * delta;
	vel.y = speed.y * direction.y * delta;
	setVelocity(vel);
	Collidable::update(delta);
}
const sf::Vector2i Player::getType()const {
	return Textures::PLAYER;
}
Player* Player::clone()const {
	return new Player(this);
}
void Player::collide( Collidable*& other) {
	Entity* ent = other->clone();
	Enemy* enemy = dynamic_cast<Enemy*>( ent );
	if(enemy) {
		remove_me = true;
	}
	delete ent;
}