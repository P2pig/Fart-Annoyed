#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color c);
	void Draw( Graphics& gfx ) const;
	bool CheckBallCollision( Ball& ball );
	void ExcuteBallCollision(Ball& ball);
	Vec2 GetCenter();
	bool getIsDestroyed();
private:
	RectF rect;
	Color c;
	bool isDestroyed = false;
	static constexpr float padding = 1.0f;
};