#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF( float left, float top, float right, float bottom );
	RectF( Vec2 topLeft, Vec2 bottomRight );
	RectF( Vec2 topLeft, float width, float height );
	bool isOverLapping( const RectF& other ) const;
	static RectF FromCenter( Vec2 center, float halfWidth, float halfHeight);
	RectF getExpanded(const float padding ) const;
	Vec2 GetCenter() const;
public:
	float top;
	float bottom;
	float left;
	float right;
};