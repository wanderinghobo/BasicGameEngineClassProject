#pragma once
#include <math.h>
#include "Entity.h"
class Ball :
	public Entity
{
public:
	float gravity;
	float angle;
	float push;

	Ball();
	~Ball();

	void moveInDirection(float angle, float push);

	void update(float dt);
	void updateMovement(float dt);
	void draw();
};

