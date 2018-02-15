#include "Brick.h"

Brick::Brick(const RectF& rect_in, Color c_in )
	:
	rect( rect_in ),
	c( c_in )
{}

void Brick::Draw( Graphics& gfx ) const
{
	if( !isDestroyed )
	{
		gfx.DrawRect( rect, c );
	}
}

bool Brick::DoBallCollision( Ball & ball )
{																									   
	if( !isDestroyed && rect.isOverLapping( ball.getRect() ) )
	{
		ball.BounceY();
		isDestroyed = true;
		return true;
	}
	return false;
}

