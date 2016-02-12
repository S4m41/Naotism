#include "Util.h"
#include "Game.h"
void wait(long double delay) {
	long double start =klock();
	long double now = -1;
	if(delay < 0)return;
	while(now < start + delay) {
		std::this_thread::yield();
		now= klock();
	}
}
long double klock() {
	return clock() / CLOCKS_PER_MS;
}
int check() {
	int i = 0;
	typedef long double ld;
	ld now = klock();
	while(now == klock()) {
		i++;
	}
	return i;
}
int cls() {
	return system("@cls||clear");
}
void Game::scarySprite(sf::RenderTarget& canvas) const {
	sf::Color c(rand() % 255 , rand() % 255 , rand() % 255);

	sf::CircleShape shape(100.f);
	shape.setFillColor(c);
	shape.setPosition((float) ( 20.0 + rand() % 10 ) , (float) ( 100 + rand() % 10 ));
	canvas.draw(shape);

	sf::CircleShape shape1(100.f);
	shape1.setFillColor(c);
	shape1.setPosition((float) ( 520 + rand() % 10 ) , (float) ( 100 + rand() % 10 ));
	canvas.draw(shape1);

	sf::RectangleShape rectangle(sf::Vector2f(520 , 100));
	rectangle.setFillColor(c);
	rectangle.setPosition(float(120 + rand() % 10) , (float) ( 400 + rand() % 5 ));
	canvas.draw(rectangle);
}