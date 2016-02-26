#pragma once
#include "Collidable.h"
class Enemy :public Collidable{
public:
public:
	Enemy::Enemy(int type = 1 , float x = 0 , float y = 0 , int mass = 0);
	Enemy::Enemy(const Enemy* /*&*/ other);
	virtual void Enemy::update(double delta);
	virtual void Enemy::collide(const Collidable*& other);
	Enemy* Enemy::clone()const;
protected:
	const virtual sf::Vector2i Enemy::getType()const;
private:
	int type;
	/*static ??*/const sf::Vector2f Enemy::getVelocityOfType(int type)const;
};
namespace ENEMY_TYPES{
	enum TYPE
	{
		ROCK = 2 ,
		TOWEL = 1 ,
		SPACESHIP = 3 ,
		A_BOMB = 4
	};

}