#pragma once
#include "Collidable.h"
class Enemy : Collidable{
public:
	Enemy::Enemy(int type = 1 , float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0);
	virtual void Enemy::update(double delta);//override
protected:
	const virtual sf::Vector2i Enemy::getType()const;
private:
	int score;
	/*
public:
	Enemy::Enemy(int type = 1 , float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0);
	virtual void Enemy::update(double delta);
protected:
	const virtual sf::Vector2i Enemy::getType()const;
private:
	int type;*/
};