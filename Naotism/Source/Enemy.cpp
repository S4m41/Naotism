#include "Enemy.h"
Enemy::Enemy(int i , float x , float y , sf::Vector2f velocity , int mass) : Collidable(x , y , velocity , mass) , score(0) {
}
void Enemy::update(double delta) {
	score += (int) ( delta += 0.5 );
	sf::Vector2f vel = getVelocity();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vel.x -= ( 1 * delta );
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vel.x += ( 1 * delta );
	}

}
const sf::Vector2i Enemy::getType()const {
	return this->texture_strct.PLAYER;
}
/*
Enemy::Enemy(int type , float x , float y , sf::Vector2f velocity , int mass) : Collidable(x , y , velocity , mass) , type(type){}

void Enemy::update(double delta) {
	this->move(getVelocity());
	//screenwrap logic here
}
const sf::Vector2i Enemy::getType()const {
	switch(type) {
	case 2:
		return texture_strct.ROCK;
	case 1:
		return texture_strct.TOWEL;
	case 3:
		return texture_strct.SPACESHIP;
	case 4:
		return texture_strct.A_BOMB;
	default:
		return Entity::getType();
	}
}
*/