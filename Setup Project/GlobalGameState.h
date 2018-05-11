#pragma once

#include <SDL.h>

enum game_state{
	MENU,
	OPTIONS,
	GAMEPLAY
};


class GlobalGameState
{
public:
	GlobalGameState();
	~GlobalGameState();

	//are declared at the start of program runtime
	static game_state currentGameState;
	static SDL_Renderer* renderer;
};

