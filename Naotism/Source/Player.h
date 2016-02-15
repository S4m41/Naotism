#pragma once
#include "Collidable.h"
class Player : public Collidable{
public:
	Player::Player(float x , float y , sf::Vector2f velocity , int mass);
	virtual void Player::update(double delta);//override
protected:
	//const virtual std::string getFilepath()const;
private:
	int score;
};
