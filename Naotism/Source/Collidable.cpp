#include "Collidable.h"
bool Collidable::isColliding(Collidable other) {
	return getGlobalBounds().intersects(other.getGlobalBounds());
}
void Collidable::Collide(Collidable other) {
	throw - 2;
}