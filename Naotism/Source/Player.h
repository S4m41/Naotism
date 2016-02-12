#pragma once
#include "Collidable.h"
class Player : public Collidable{
public:
	virtual void Player::update(double delta);//override
protected:
	//const virtual std::string getFilepath()const;
private:
	int score;
};
