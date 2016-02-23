#include "Collidable.h"
Collidable::Collidable(float x , float y , sf::Vector2f velocity , int mass) :Entity(x , y , velocity) {
	setMass(mass);
}
bool Collidable::isColliding(Collidable other) {
	return getGlobalBounds().intersects(other.getGlobalBounds());
Collidable::Collidable(const Collidable* /*&*/other) :Entity(other) {
	setMass(other->getMass());
}
void Collidable::Collide(Collidable other) {
	throw - 2;
}
void Collidable::setMass(int mass) {
	this->mass = mass;
}
int Collidable::getMass() {
	return mass;
}