#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF( float left, float top, float right, float bottom );
	RectF( Vec2 topLeft, Vec2 bottomRight );
	RectF( Vec2 topLeft, float width, float height );
	bool IsColliding( const RectF& other ) const;
public:
	float top;
	float bottom;
	float left;
	float right;
};