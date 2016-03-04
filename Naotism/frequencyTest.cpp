#define RES (10e3)
#include "External\SFML-2.3.2\include\SFML\Window\Keyboard.hpp"
#include "Source\Util.h"
#include <iostream>
using namespace std;
void update(long double delta , int &tick);
int main() {
	typedef long double ld;
	srand((unsigned int) time(NULL));
	const int TARGET_FPS = 34;
	ld lastFpsTime = 0;
	int fps = 0;
	int tick = 0;

	ld lastLoopTime = klock();
	const ld OPTIMAL_TIME = RES / TARGET_FPS;

	//main loop
	while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		ld now = klock();
		ld updateLength = now - lastLoopTime;
		lastLoopTime = now;
		double delta = updateLength / ( (double) OPTIMAL_TIME );



		//fpscounter
		lastFpsTime += updateLength;
		fps++;
		if(lastFpsTime >= RES) {
			cout << "(FPS: " << fps << ")" << endl;

			lastFpsTime = 0;
			fps = 0;

		}

		while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		}
		// update the game logic
		update(delta , tick);
		wait(( lastLoopTime - klock() + OPTIMAL_TIME )*( RES / 10e3 ));
	}
}
void update(long double delta , int &tick) {
	tick += 1;//+ (int) (delta + 0.5 );
	const int dist = 2;
	const int peak = 500;
	int i = 0;
	double d = bell(tick , peak*pow(dist,i++));
	double e = bell(tick , peak*pow(dist , i++));
	double f = bell(tick , peak*pow(dist , i++)) , g = bell(tick , peak*pow(dist , i++));

	//cout << i << endl;
	if(rand()%100 < d) {
		cout << "1" << "\t";
	}
	if(rand() %100< e) {
		cout << "2" << "\t";
	}
	if(rand() %100 < f) {
		cout << "3" << "\t";
	}
	if(rand() % 100 < g) {
		cout << "4" << "\t";
	}/*
	if(rand() % tick > 200) {
		cout << "2" << "\t";
	}
	if(rand() % tick > 500) {
		cout << "3" << "t";
	}
	if(rand() % tick > 1e3) {
		cout << "4" << "\t";
	}*/

}