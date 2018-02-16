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

bool RectF::isOverLapping( const RectF& other ) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

RectF RectF::FromCenter( Vec2 center, float halfWidth, float halfHeight )
{
	Vec2 half( halfWidth, halfHeight );
	return RectF( center - half, center + half );
}

RectF RectF::getExpanded( const float padding ) const
{
	return RectF( left - padding, top - padding, right + padding, bottom + padding );
}

Vec2 RectF::GetCenter() const
{
	return Vec2( (left + right) / 2.0f, (top + bottom) / 2.0f ); 
}
