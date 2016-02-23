#pragma once
#include "Collidable.h"
class Enemy :public Collidable{
public:
public:
	Enemy::Enemy(int type = 1 , float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0);
	Enemy::Enemy(const Enemy* /*&*/ other);
	virtual void Enemy::update(double delta);
	virtual void Enemy::collide(const Collidable*& other)const;
	Enemy* Enemy::clone()const;
protected:
	const virtual sf::Vector2i Enemy::getType()const;
private:
	int type;
};