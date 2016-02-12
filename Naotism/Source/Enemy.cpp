#include "Enemy.h"

void Enemy::update(double delta) {
	this->move(getVelocity());
	//screenwrap logic here
}