#pragma once

#include "RectF.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const RectF& rect_in, Color c);
	void Draw( Graphics& gfx ) const;
private:
	RectF rect;
	Color c;
	bool isDestroyed = false;
};