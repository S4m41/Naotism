#include <iostream>
#include "External\SFML-2.3.2\include\SFML\Graphics.hpp"
using namespace std;
int main(int argc , char* argv[]) {
	
	sf::Image image;
	if(!image.loadFromFile("Placeholder.png")) {
		std::cout << "Could not load sprite image\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	sf::Texture texture= sf::Texture();
	texture.loadFromImage(image);
	sf::Sprite sprite(texture);
	sprite.setColor(sf::Color(0 , 255 , 255 , 128));
	sprite.setPosition(200.f , 100.f);
	sprite.setScale(2.0f , 2.0f);
	sf::RenderWindow app(sf::VideoMode(800 , 600 , 32) , "SFML Graphics");
	while(app.isOpen()) {
		sf::Event e;
		while(app.pollEvent(e)) {
			if(e.type == sf::Event::Closed) {
				app.close();
			}
		}

		app.clear(sf::Color(0 , 0 , 0));
		app.draw(sprite);
		app.display();
	}
	return EXIT_SUCCESS;
}