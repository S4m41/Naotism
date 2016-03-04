#include "Vector.h"
Vector_E::Vector_E() {
	arr = new Entity*[capacity];
}
Vector_E::~Vector_E() {
	clear();
	delete[] arr;
}
Entity* Vector_E::at(int i) /*throw( ... )*/ const {
	if(i > contains) {
		throw "Out of bounds";
	}
	return arr[i];
}
void Vector_E::clear() {
	for(int i = 0; i < size(); i++) {
		delete arr[i];
	}
	contains = 0;
}
void Vector_E::push_back(Entity* e) {
	if(contains >= capacity) {
		expand();
	}
	arr[contains++] = e;
}
_inline int Vector_E::size() const{
	return contains;
}

void Vector_E::expand() {
	Entity** templist = new Entity*[capacity + 5];
	for(int i = 0; i < size(); i++) {
		templist[i] = arr[i];
	}
	delete[] arr;
	arr = templist;
	capacity += 5;
}
void Vector_E::erase(int i) {
	contains--;
	Entity* e = arr[i];
	arr[i] = arr[contains];
	arr[contains] = e;

	delete e;
}