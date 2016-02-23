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
	( *texture ).loadFromImage(image , sf::IntRect(texture_strct.spritesize.x*typerect.x , texture_strct.spritesize.y*typerect.y , texture_strct.spritesize.x , texture_strct.spritesize.y));

	this->setTexture(*texture);
	txture_ptr = texture;
}
void Entity::update(double delta) {
	move(velocity);
}
const sf::Vector2i Entity::getType()const {
	return this->texture_strct.PLACEHOLDER;
}