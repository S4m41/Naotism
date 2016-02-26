#include "Enemy.h"
#include "Engine.h"
Enemy::Enemy(int type , float x , float y , int mass) : Collidable(x , y , getVelocityOfType(type) , mass) , type(type) {
}
Enemy::Enemy(const Enemy* /*&*/ other) : Collidable(other) {
	type = other->type;
}
void Enemy::update(double delta) {
	sf::Vector2f vec = getVelocityOfType(type);
	this->setVelocity(vec.x*delta , vec.y*delta);
	/*if(this->getGlobalBounds().left < 0
		|| this->getGlobalBounds().width + this->getGlobalBounds().left < SCREENSIZES::LARGE.x)

		setVelocity(getVelocity().x*-1 , 0);*/

	if(this->getGlobalBounds().top < SCREENSIZES::LARGE.y)
		remove_me = true;

	Collidable::update(delta);
}
const sf::Vector2i Enemy::getType()const {
	switch(type) {
	case ENEMY_TYPES::ROCK:
		return texture_strct.ROCK;

	case ENEMY_TYPES::TOWEL:
		return texture_strct.TOWEL;

	case ENEMY_TYPES::SPACESHIP:
		return texture_strct.SPACESHIP;

	case ENEMY_TYPES::A_BOMB:
		return texture_strct.A_BOMB;
	default:
		return Entity::getType();
	}
}
Enemy* Enemy::clone()const {
	return new Enemy(this);
}
void Enemy::collide(const Collidable*& other) {
	/*sf::Vector2f vel = getVelocity();
	float x = ( vel.x* ( getMass() - other->getMass() ) + 2 * other->getMass()*other->getVelocity().x )
		/ ( getMass() + other->getMass() );
	float y = ( vel.y* ( getMass() - other->getMass() ) + 2 * other->getMass()*other->getVelocity().y )
		/ ( getMass() + other->getMass() );

	setVelocity(x , y);*/
}
const sf::Vector2f Enemy::getVelocityOfType(int type)const {
	switch(type) {
	case ENEMY_TYPES::ROCK:
		return sf::Vector2f(10 , 10);//texture_strct.ROCK;
	case ENEMY_TYPES::TOWEL:
		return sf::Vector2f(2 , 2);//texture_strct.TOWEL;
	case ENEMY_TYPES::SPACESHIP:
		return sf::Vector2f(20 , 20);//texture_strct.SPACESHIP;
	case ENEMY_TYPES::A_BOMB:
		return sf::Vector2f(25 , 25);//texture_strct.A_BOMB;
	default:
		return sf::Vector2f(0 , 0);//Entity::getType();

	}
}