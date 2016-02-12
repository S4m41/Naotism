#pragma once
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics.hpp"
class Entity : public sf::Sprite{
public:
	virtual ~Entity();

	sf::Vector2f Entity::getVelocity();
	void Entity::setVelocity(sf::Vector2f);
	void Entity::setVelocity(float x , float y);

	virtual void init();
	virtual void update(double delta);
protected:
	const virtual std::string getFilepath()const;
private:
	sf::Vector2f velocity = sf::Vector2f(0 , 0);
	sf::Texture* txture_ptr;
};