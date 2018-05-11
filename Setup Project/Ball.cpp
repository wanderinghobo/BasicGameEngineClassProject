#include "Ball.h"


Ball::Ball()
{
	velocity.x = 0;
	velocity.y = 0;
	gravity = 200; //accumulates at pixels per second
	angle = 70;
	push = 270;

	velocity.x = push*cos(angle / 180 * M_PI);
	velocity.y =(push*sin(angle/180*M_PI));
}


Ball::~Ball()
{
}

void Ball::moveInDirection(float angle, float push){
	this->angle = angle;
	this->push = push;
	velocity.x = push*cos(angle / 180 * M_PI);
	velocity.y = (push*sin(angle / 180 * M_PI));
}

void Ball::update(float dt){
	//DEAL WITH GRAVITY
	if (pos.y < 480){
		velocity.y += gravity*dt;
	}
	

	
	//bounce off the walls
		//left wall							//right wall
	if ((pos.x <= 0 && velocity.x <= 0) || (pos.x >= 640 && velocity.x >= 0))
	{
		velocity.x = velocity.x*-0.7;
	}
	//bounce off roof
	if ((pos.y <= 0 && velocity.y <= 0))
	{
		velocity.y = velocity.y*-0.7;
	}
	//bounce off ground
	if (pos.y > 480){
		//force us back on screen
		pos.y = 480;
		//if moving quick enough, bounce back up
		if (velocity.y >= 20)
			velocity.y = velocity.y*-0.7;
		else //else, stop bouncing
			velocity.y = 0;
	}

	updateMovement(dt);
}

void Ball::updateMovement(float dt){
	pos.x = pos.x + velocity.x*dt;
	pos.y = pos.y + velocity.y*dt;

}
void Ball::draw(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect ballRect = { pos.x - 25, pos.y - 25, 50, 50 };
	SDL_RenderFillRect(renderer, &ballRect);
}