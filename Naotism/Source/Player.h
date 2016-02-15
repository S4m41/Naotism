#pragma once
#include "Collidable.h"
class Player : public Collidable{
public:
	Player::Player(int type = 1 , float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0);
	virtual void Player::update(double delta);//override
protected:
	const virtual sf::Vector2i Player::getType()const;
private:
	int score;
};