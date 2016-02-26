#include "Collidable.h"
#include "Engine.h"
Collidable::Collidable(float x , float y , sf::Vector2f velocity , int mass) :Entity(x , y , velocity) {
	setMass(mass);
}
Collidable::Collidable(const Collidable* /*&*/other) :Entity(other) {
	setMass(other->getMass());
}
bool Collidable::isColliding(const Collidable* other) const{
	return getGlobalBounds().intersects(other->getGlobalBounds());
}
void Collidable::setMass(int mass) {
	this->mass = mass;
}
int Collidable::getMass()const {
	return mass;
}
void Collidable::update(double delta) {
	if(this->getGlobalBounds().left + this->getGlobalBounds().width<0) {//TODO polish
		this->move(SCREENSIZES::LARGE.x - this->getGlobalBounds().left , 0);
	} else if(this->getGlobalBounds().left > SCREENSIZES::LARGE.x) {
		this->move(-( this->getGlobalBounds().left + this->getGlobalBounds().width/2 ) , 0);
	}
	Entity::update(delta);
}