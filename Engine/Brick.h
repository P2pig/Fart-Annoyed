#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& rect_in, Color c);
	void Draw( Graphics& gfx ) const;
	bool DoBallColliding(Ball& ball);
private:
	RectF rect;
	Color c;
	bool isDestroyed = false;
};