#pragma once
#include "Collidable.h"
class Enemy : Collidable{
public:
	virtual void update(double delta);
protected:
	const virtual sf::Vector2i Enemy::getType()const;
private:
	int type;
};