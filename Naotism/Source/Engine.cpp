#include "Engine.h"

#define RES (10e3)
using namespace std;

Engine::Engine() {
}
Engine::~Engine() {
	delete myGame;

}

void Engine::init() {
	init(new Game());
}
void Engine::init(Game* currGame) {
	lastFpsTime = 0;
	fps = 0;
	window.create(sf::VideoMode(screensize.x , screensize.y) , "Naotism" , sf::Style::Titlebar | sf::Style::Close);
	currGame->init();
	//currGame->problem(Errors::Close);
	this->myGame = currGame;

}
void Engine::main_loop() {

	typedef long double ld;
	ld lastLoopTime = klock();
	const ld OPTIMAL_TIME = RES / this->TARGET_FPS;
	bool gameRunning = true;
	sf::RenderTexture renderTexture;
	if(!renderTexture.create(SCREENSIZES::FULLSCREEN.x , SCREENSIZES::FULLSCREEN.y)) {
		gameRunning = false;
		std::cout << "Failed to create doublebuffer" << std::endl;
		throw - 11;
		// error...
	}
	//main loop
	while(this->myGame->isRunning() && window.isOpen()) {
		ld now = klock();
		ld updateLength = now - lastLoopTime;
		lastLoopTime = now;
		double delta = updateLength / ( (double) OPTIMAL_TIME );

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
		}

		//fpscounter
		fpsCount(updateLength);


		// update the game logic
		myGame->update(delta);

		// drawing uses the same functions
		renderTexture.clear();
		renderTexture.draw(*myGame); // or any other drawable
		renderTexture.display();

		// get the target texture (where the stuff has been drawn)
		const sf::Texture& texture = renderTexture.getTexture();

		// draw it to the window
		sf::Sprite sprite(texture);
		window.draw(sprite);
		window.display();
		//wait(( lastLoopTime - klock() + OPTIMAL_TIME )*( RES / 10e3 ));

	}
	if(!myGame->isRunning()) {
		std::cout << myGame->getErrors() << std::endl;
	}

}
void Engine::fpsCount(long double updateLength) {

	lastFpsTime += updateLength;
	fps++;
	if(lastFpsTime >= RES) {
		cout << "(FPS: " << fps << ")" << endl;

		lastFpsTime = 0;
		fps = 0;

	}
}
void Engine::handleWindowEvents() {

	//windowevents
	sf::Event event;
	while(window.pollEvent(event)) {
		if(event.type == sf::Event::Closed)
			window.close();
	}
	cout << "<";

}

