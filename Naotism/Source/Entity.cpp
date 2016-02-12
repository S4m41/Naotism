#include "Entity.h"
Entity::~Entity() {
	delete txture_ptr;
}
sf::Vector2f Entity::getVelocity() {
	return this->velocity;
}
void Entity::setVelocity(sf::Vector2f toSet) {
	velocity = toSet;
}
void Entity::setVelocity(float x , float y) {
	setVelocity(sf::Vector2f(x , y));
}
void Entity::init() {
	this->setPosition(50 , 50);

	
	sf::Texture* texture = new sf::Texture();
	sf::Image image;
	image.create(1000 , 1000);
	
	if(!image.loadFromFile(getFilepath()))throw -12;
	(*texture).loadFromImage(image , sf::IntRect(0 , 0 , 64 , 64));
	//if(!( texture ).loadFromFile("/Resources/Placeholder.png" , sf::IntRect(0 , 0 , 54 , 54)));
	//								\\storage10.student.bth.se\students\20152\silg15\visual studio 2013\Projects\Naotism\Naotism\Resources
	this->setTexture(*texture);
	txture_ptr = texture;
}
void Entity::update(double delta) {
}
const std::string Entity::getFilepath()const {
	return "Resources\\Placeholder.png";
}