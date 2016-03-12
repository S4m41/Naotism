#pragma once
#include "Collidable.h"

namespace ENEMY_TYPES{
	enum TYPE
	{
		TOWEL = 1 ,
		ROCK = 2 ,
		SPACESHIP = 3 ,
		A_BOMB = 4
	};
}

class Enemy :public Collidable{
public:
public:
	Enemy::Enemy(int type = 1 , float x = 0 , float y = 0 , int mass = 0);
	Enemy::Enemy(const Enemy* /*&*/ other);
	virtual void Enemy::update(float delta);
	virtual void Collidable::collide(Collidable*& other);
	Enemy* Enemy::clone()const;
protected:
	const virtual sf::Vector2i Enemy::getType()const;
private:
	int type;
	/*static ??*/_inline const sf::Vector2f Enemy::getVelocityOfType(int type)const;
};