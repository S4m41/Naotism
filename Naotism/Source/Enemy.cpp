#include "Enemy.h"
#include "Engine.h"
Enemy::Enemy(int type , float x , float y , int mass) : Collidable(x , y , getVelocityOfType(type) , mass) , type(type) {
}
Enemy::Enemy(const Enemy* /*&*/ other) : Collidable(other) {
	type = other->type;
}
void Enemy::update(float delta) {
	sf::Vector2f vec = getVelocityOfType(type);
	this->setVelocity(vec.x*delta , vec.y*delta);
	float top = this->getGlobalBounds().top;
	int screen_bottom = SCREENSIZES::screensize_bad.y;
	if(top> screen_bottom)
		remove_me = true;

	Collidable::update(delta);
}
const sf::Vector2i Enemy::getType()const {
	switch(type) {
	case ENEMY_TYPES::ROCK:
		return Textures::ROCK;

	case ENEMY_TYPES::TOWEL:
		return Textures::TOWEL;

	case ENEMY_TYPES::SPACESHIP:
		return Textures::SPACESHIP;

	case ENEMY_TYPES::A_BOMB:
		return Textures::A_BOMB;
	default:
		return Entity::getType();
	}
}
Enemy* Enemy::clone()const {
	return new Enemy(this);
}

const sf::Vector2f Enemy::getVelocityOfType(int type)const {
	switch(type) {
	case ENEMY_TYPES::TOWEL:
		return sf::Vector2f(0 , 2);//Textures::TOWEL;
	case ENEMY_TYPES::ROCK:
		return sf::Vector2f(0 , 4);//Textures::ROCK;
	case ENEMY_TYPES::SPACESHIP:
		return sf::Vector2f(0 , 8);//Textures::SPACESHIP;
	case ENEMY_TYPES::A_BOMB:
		return sf::Vector2f(0 , 12);//Textures::A_BOMB;
	default:
		return sf::Vector2f(0 , 15);//Entity::getType();

	}
}
void Enemy::collide(Collidable*& other) {}