#pragma once

#include "RectF.h"
#include "Beveler.h"

class Walls
{
public:
	Walls( const RectF& innerBounds_in, float thinkness_in, Color baseColor );
	const RectF& GetInnerBounds() const;
	void Draw( Graphics& gfx ) const;
private:
	RectF innerBounds;
	float thickness;
	Beveler bev;
};