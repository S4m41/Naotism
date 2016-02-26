#pragma once
#include "Collidable.h"
class Player : public Collidable{
public:
	Player::Player( float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0) , int mass = 0);
	Player::Player(const Player* /*&*/other);
	virtual void Player::update(double delta);//override
	virtual Player* Player::clone()const;
	virtual void Player::collide(const Collidable*& other);
protected:
	const virtual sf::Vector2i Player::getType()const;
private:
	sf::Vector2i direction = sf::Vector2i(0,0);
	sf::Vector2f speed = sf::Vector2f(2 , 0.01f);
	int score=0;
};