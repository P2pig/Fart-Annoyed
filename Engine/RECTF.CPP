#include "RectF.h"

RectF::RectF( float left, float right, float top, float bottom )
	:
	left( left ),
	right( right ),
	top( top ),
	bottom( bottom )
{}

RectF::RectF( Vec2 topLeft, Vec2 bottomRight )
	:
	RectF( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y )
{}

RectF::RectF( Vec2 topLeft, float width, float height )
	:
	RectF( topLeft, Vec2( width, height ) )
{}

bool RectF::IsColliding( const RectF& other ) const
{
	return right >= other.left
		&& left <= other.right
		&& bottom >= other.top
		&& top <= other.bottom;
}