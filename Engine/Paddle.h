#pragma once

#include "Vec2.h"
#include "Keyboard.h"
#include "RectF.h"
#include "Ball.h"
#include "Graphics.h"

class Paddle
{
public:
	Paddle( const Vec2& pos, float halfWidth, float halfHright );
	void Update( Keyboard& kbd, float dt );
	void DoWallCollision( const RectF& wall );
	bool DoBallCollision( Ball& ball ) const;
	void Draw( Graphics& gfx ) const;
	RectF getRect() const;
private:
	static constexpr float wingWidth = 18.0f;
	Color wingColor = Colors::Red;
	Color color = Colors::White;
	float halfWidth;
	float halfHeight;
	float speed = 300.0f;
	Vec2 pos;
};