#pragma once
#include "Entity.h"
class Collidable : public Entity{
public:
	bool Collidable::isColliding(Collidable other);
	void Collidable::Collide(Collidable other);
private:
	int mass;

};