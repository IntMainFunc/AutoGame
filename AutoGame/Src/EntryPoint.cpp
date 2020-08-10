#include "AgPch.h"

#include "Include/AgGameEngine.h"

int main()
{
	Ag::App* game = new Ag::App();
	game->Run();
	delete game;
}