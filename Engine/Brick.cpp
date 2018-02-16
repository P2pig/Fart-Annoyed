#include "Brick.h"
#include <assert.h>

Brick::Brick( const RectF& rect_in, Color c_in )
	:
	rect( rect_in ),
	c( c_in )
{}

void Brick::Draw( Graphics& gfx ) const
{
	if( !isDestroyed )
	{
		gfx.DrawRect( rect.getExpanded( -padding ), c );
	}
}

bool Brick::CheckBallCollision( Ball & ball )
{
	return !isDestroyed && rect.isOverLapping( ball.getRect() );
}

void Brick::ExcuteBallCollision( Ball & ball )
{
	assert( CheckBallCollision( ball ) );
	if( CheckBallCollision( ball ) )
	{
		Vec2 ballPos = ball.getPosition();
		if( std::signbit( ball.getVelocity().x ) == std::signbit( (ballPos - GetCenter()).x ) )
		{
			ball.BounceY();
		}
		else if( ballPos.x > rect.left && ballPos.x < rect.right )
		{
			ball.BounceY();
		}
		else
		{
			ball.BounceX();
		}
		isDestroyed = true;
	}
}

Vec2 Brick::GetCenter()
{
	return rect.GetCenter();
}

