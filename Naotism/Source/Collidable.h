#pragma once
#include "Entity.h"
class Collidable : public Entity{
public:
	Collidable(float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0),int mass = 1) ;
	bool Collidable::isColliding(Collidable other);
	void Collidable::Collide(Collidable other);
	void Collidable::setMass(int mass);
	int Collidable::getMass();
private:
	int mass;

};