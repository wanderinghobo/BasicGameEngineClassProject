#include "MenuScreenState.h"


MenuScreenState::MenuScreenState()
{
}


MenuScreenState::~MenuScreenState()
{
}

void MenuScreenState::update(){
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT){
			//exit our loop,

		}
		if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
				//exit loop
				//TODO exit game somehow
			}
			if (e.key.keysym.scancode == SDL_SCANCODE_SPACE){
				//start the game!
				//TODO change to gameplay state
			}
		}
	}
}
void MenuScreenState::render(){
	//                                                R    G  B   Alpha
	SDL_SetRenderDrawColor(GlobalGameState::renderer, 173, 0, 0, 255);
	SDL_RenderClear(GlobalGameState::renderer);

	SDL_RenderPresent(GlobalGameState::renderer);
}
bool MenuScreenState::onEnter(){
	std::cout << "Entering menu state" << std::endl;
	return true;
}
bool MenuScreenState::onExit(){
	std::cout << "Exiting menu state" << std::endl;
	return true;
}