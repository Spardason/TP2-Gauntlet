#include "Engine.h"
#include "Game.h"

int main(int argc, char* args[])
{
	Engine::GetInstance()->Init(800, 600, RESOLUTION_NTSC);

	Game *game = new Game();

	Engine::GetInstance()->Run();

	delete game;

	return 0;
}