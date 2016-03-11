#pragma once
#include "Collidable.h"
#include "Engine.h"
class Player : public Collidable{
public:
	Player::Player(float x = SCREENSIZES::screensize_bad.x / 2 , float y = SCREENSIZES::screensize_bad.y - 64 
		, sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0) :Collidable(x,y,velocity,mass){}
	Player::Player(const Player* other) :Collidable(other){}
	virtual void Player::update(float delta);//override
	virtual Player* Player::clone()const;
	virtual void Player::collide( Collidable*& other);
protected:
	const virtual sf::Vector2i Player::getType()const;
private:
	sf::Vector2i direction = sf::Vector2i(0,0);
	sf::Vector2f speed = sf::Vector2f(7 , 0.01f);
	
};
