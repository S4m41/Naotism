#pragma once
#include "Entity.h"
class Collidable : public Entity{
public:
	Collidable(float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0),int mass = 1) ;
	Collidable(const Collidable* /*&*/ other);
	bool Collidable::isColliding(const Collidable* other)const;
	virtual void Collidable::collide( Collidable*& other)= 0;
	void Collidable::setMass(int mass);
	int Collidable::getMass()const;
	void Collidable::update(float delta);
private:
	int mass;

	

};