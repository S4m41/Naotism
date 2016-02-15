#pragma once
#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics.hpp"
class Entity : public sf::Sprite{
public:
	Entity::Entity(float x = 0 , float y = 0 , sf::Vector2f velocity = sf::Vector2f(0 , 0));
	virtual ~Entity();

	sf::Vector2f Entity::getVelocity();
	void Entity::setVelocity(sf::Vector2f);
	void Entity::setVelocity(float x , float y);

	virtual void init();
	virtual void update(double delta);
protected:
	const sf::Vector2i Entity::getType()const;

	typedef  const struct __t {
		const sf::Vector2i spritesize = sf::Vector2i(64 , 64);
		//>should be enum<

		const sf::Vector2i PLACEHOLDER = sf::Vector2i(0 , 0);
		const sf::Vector2i PLAYER = sf::Vector2i(1 , 0);
		const sf::Vector2i ROCK = sf::Vector2i(2 , 0);
		const sf::Vector2i TOWEL = sf::Vector2i(0 , 1);
		const sf::Vector2i SPACESHIP = sf::Vector2i(1 , 1);
		const sf::Vector2i A_BOMB = sf::Vector2i(2 , 1);
		const sf::Vector2i DISTRACTION_1 = sf::Vector2i(0 , 2);
		const sf::Vector2i DISTRACTION_2 = sf::Vector2i(1 , 2);
		const sf::Vector2i DISTRACTION_3 = sf::Vector2i(2 , 2);

		//>should be enum!<
	}Textures;
	const Textures texture_strct;
private:
	sf::Vector2f velocity = sf::Vector2f(0 , 0);
	sf::Texture* txture_ptr;


};
