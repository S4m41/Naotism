#pragma once
#include "Entity.h"
class Vector_E
{
public:
	Vector_E::Vector_E();
	virtual Vector_E::~Vector_E();
	Entity* Vector_E::at(int i) /*throw( ... )*/const;
	void Vector_E::clear();
	void Vector_E::push_back(Entity* e);
	_inline int Vector_E::size()const;
	void Vector_E::erase(int i);
private:
	void Vector_E::expand();
	Entity** arr;
	int capacity = 5 , contains = 0;
};