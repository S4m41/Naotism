#include "Enemy.h"
#include "Engine.h"
Enemy::Enemy(int type , float x , float y , sf::Vector2f velocity , int mass) : Collidable(x , y , velocity , mass) , type(type){}
Enemy::Enemy(const Enemy* /*&*/ other): Collidable(other) {
	type = other->type;
}
void Enemy::update(double delta) {
	
	/*if(this->getGlobalBounds().left < 0 
		|| this->getGlobalBounds().width + this->getGlobalBounds().left < SCREENSIZES::LARGE.x) 
		
		setVelocity(getVelocity().x*-1 , 0);*/

	if(this->getGlobalBounds().top < SCREENSIZES::LARGE.y)
		remove_me = true;

	Collidable::update(delta);
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
Enemy* Enemy::clone()const {
	return new Enemy(this);
}
void Enemy::collide(const Collidable*& other) {
	sf::Vector2f vel = getVelocity();
	float x = ( vel.x* ( getMass() - other->getMass() ) + 2 * other->getMass()*other->getVelocity().x )
		/ ( getMass() + other->getMass() );
	float y = ( vel.y* ( getMass() - other->getMass() ) + 2 * other->getMass()*other->getVelocity().y )
		/ ( getMass() + other->getMass() );
	
	setVelocity(x,y);
}