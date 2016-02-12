#pragma once
#include "Collidable.h"
class Enemy : Collidable{
public:
	virtual void update(double delta);
protected:
	//const virtual std::string getFilepath()const;
};