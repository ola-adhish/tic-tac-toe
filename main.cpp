#include "game.h"
#include <iostream>

int main()
{
	Game* g = new Game(3);
	
	g->Play();
	
	delete g;
	g = NULL;
	
	return 0;
}
