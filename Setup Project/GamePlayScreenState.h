#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameState.h"
#include "GlobalGameState.h"
#include <iostream>
#include "Hero.h"
#include "Ball.h"

using namespace std;

class GamePlayScreenState :
	public GameState
{
public:
	//we're gonna add textures and stuff here as attributes
	SDL_Texture* heroTexture;
	Animation* heroAnimation;
	Hero* hero;
	Ball* ball1;
	Ball* ball2;
	SDL_Texture* textTexture;

	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt = 0;//time since last update

	GamePlayScreenState();
	~GamePlayScreenState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "gamePlayState"; }
};

