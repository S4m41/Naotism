#pragma once
#include "Collidable.h"
#include "Engine.h"//please don't
class Player : public Collidable{
public:
	Player::Player(float x = SCREENSIZES::LARGE.x / 2 , float y = SCREENSIZES::LARGE.y - 64 , sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0);
	Player::Player(const Player* /*&*/other);
	virtual void Player::update(double delta);//override
	virtual Player* Player::clone()const;
	virtual void Player::collide( Collidable*& other);
protected:
	const virtual sf::Vector2i Player::getType()const;
private:
	sf::Vector2i direction = sf::Vector2i(0,0);
	sf::Vector2f speed = sf::Vector2f(7 , 0.01f);
	
};