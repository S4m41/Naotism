#include "Engine.h"

#define RES (10e2)
using namespace std;

Engine::~Engine() {
	delete myGame;
}

void Engine::init() {
	init(new Game());
}
_inline void Engine::init(Game* currGame) {
	lastFpsTime = 0;
	fps = 0;
	screensize = SCREENSIZES::screensize_bad;
	window.create(sf::VideoMode(screensize.x , screensize.y) , "Naotism - " , sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(65);
	window.setVerticalSyncEnabled(false);
	currGame->init();
	this->myGame = currGame;

}
void Engine::main_loop() {
	sf::RenderTexture renderTexture;
	if(!renderTexture.create(SCREENSIZES::FULLSCREEN.x , SCREENSIZES::FULLSCREEN.y)) {
		myGame->problem(Errors::Other);
		std::cout << "Failed to create doublebuffer" << std::endl;
		throw - 11;
	}

	typedef long double ld;
	clock.restart();
	const ld OPTIMAL_TIME = RES / this->TARGET_FPS;
	
	//main loop
	while(this->myGame->isRunning() && window.isOpen()) {
		sf::Int32 updateLength = clock.restart().asMilliseconds();
		float delta = updateLength / ( (float) OPTIMAL_TIME );

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
		}

		// update the game logic
		myGame->update(delta);

		// drawing 
		renderTexture.clear();
		renderTexture.draw(*myGame); 
		renderTexture.display();

		// get the target texture (where the stuff has been drawn)
		const sf::Texture& texture = renderTexture.getTexture();

		// draw it to the window
		sf::Sprite sprite(texture);
		window.draw(sprite);
		window.display();
		lastFpsTime += updateLength;
		fps++;
		if(lastFpsTime >= RES) {
			cout << "(FPS: " << std::to_string(fps) << ")" << endl;

			lastFpsTime = 0;
			fps = 0;
		}
	}
	if(!myGame->isRunning()) {
		std::cout << myGame->getErrors() << std::endl;
	}
}
