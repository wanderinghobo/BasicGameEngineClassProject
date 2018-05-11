#include "GamePlayScreenState.h"


GamePlayScreenState::GamePlayScreenState()
{
	SDL_Surface* runSurface = IMG_Load("assets/run.png");
	//tell surface which colour should be invisible
	SDL_SetColorKey(runSurface, 1, SDL_MapRGB(runSurface->format, 128, 128, 255));
	//convert it to texture
	heroTexture = SDL_CreateTextureFromSurface(GlobalGameState::renderer, runSurface);
	//cleanup surface memory
	SDL_FreeSurface(runSurface);

	heroAnimation = new Animation(heroTexture, GlobalGameState::renderer, 4, 32, 32, 0.8);

	Hero* hero = new Hero();
	hero->setAnimation(heroAnimation);
	hero->setRenderer(GlobalGameState::renderer);
	hero->pos.x = 200;
	hero->pos.y = 200;


}

GamePlayScreenState::~GamePlayScreenState()
{
	//delete everything we need to
	delete hero;
	delete heroAnimation;
	SDL_DestroyTexture(heroTexture);
}

void GamePlayScreenState::update(){
	//update our delta time
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;

	//TODO DEAL WITH USER INPUT

	hero->update(dt);
}
void GamePlayScreenState::render(){
	SDL_SetRenderDrawColor(GlobalGameState::renderer, 255, 90, 0, 255);

	SDL_RenderClear(GlobalGameState::renderer);

	hero->draw();

	SDL_RenderPresent(GlobalGameState::renderer);
}
bool GamePlayScreenState::onEnter(){
	cout << "Enter Gameplay state" << endl;
	return true;
}
bool GamePlayScreenState::onExit(){
	cout << "Exit Gameplay state" << endl;
	return true;
}