#include "RectF.h"

RectF::RectF( float left, float top, float right, float bottom )
	:
	left( left ),
	right( right ),
	top( top ),
	bottom( bottom )
{}

RectF::RectF( Vec2 topLeft, Vec2 bottomRight )
	:
	RectF( topLeft.x, topLeft.y, bottomRight.x, bottomRight.y )
{}

RectF::RectF( Vec2 topLeft, float width, float height )
	:
	RectF( topLeft, Vec2( width, height ) + topLeft )
{}

bool RectF::IsColliding( const RectF& other ) const
{
	return right >= other.left
		&& left <= other.right
		&& bottom >= other.top
		&& top <= other.bottom;
}