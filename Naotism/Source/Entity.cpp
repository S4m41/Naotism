#include "Entity.h"
Entity::Entity(float x , float y , sf::Vector2f velocity) :sf::Sprite() {
	setPosition(x , y);
	setVelocity(velocity);
}
Entity::Entity(const Entity* /*&*/ other):sf::Sprite() {
	setPosition(other->getPosition());
	setVelocity(other->getVelocity());
}
Entity::~Entity() {
	delete txture_ptr;
}
sf::Vector2f Entity::getVelocity()const {
	return this->velocity;
}
void Entity::setVelocity(sf::Vector2f toSet) {
	velocity = toSet;
}
void Entity::setVelocity(float x , float y) {
	setVelocity(sf::Vector2f(x , y));
}
void Entity::init() {
	sf::Texture* texture = new sf::Texture();
	sf::Image image;
	image.create(1000 , 1000);

	if(!image.loadFromFile("Resources\\spritesheet.png"))throw - 12;
	sf::Vector2i typerect = getType();
	sf::IntRect rect = sf::IntRect(
		Textures::spritesize.x*typerect.x , Textures::spritesize.y*typerect.y , 
		Textures::spritesize.x , Textures::spritesize.y);
	( *texture ).loadFromImage(image , rect);

	this->setTexture(*texture);
	txture_ptr = texture;

	this->setOrigin(rect.width/2,this->getOrigin().y);
}
void Entity::update(float delta) {
	move(velocity);
}
const sf::Vector2i Entity::getType()const {
	return Textures::PLACEHOLDER;
}
const bool Entity::isDead() const{
	return remove_me;
}
