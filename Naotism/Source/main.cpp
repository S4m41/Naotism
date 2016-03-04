#include "Engine.h"
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int) time(NULL));
	
	Engine e;
	e.init();

	e.main_loop();
	return 0;
}