#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball( const Vec2 & pos_in, const Vec2 & vel_in )
	:
	pos( pos_in ),
	vel( vel_in )
{}

void Ball::Draw( Graphics& gfx )
{
	SpriteCodex::DrawBall( pos, gfx );
}

void Ball::Update( float dt )
{
	pos += vel * dt;
}

bool Ball::DoWallCollision( const RectF & wall )
{
	bool isColliding = false;

	RectF rect = getRect();
	if( rect.left <= wall.left )
	{
		pos.x += wall.left - rect.left;
		BounceX();
		isColliding = true;
	}
	else if( rect.right > wall.right )
	{
		pos.x += wall.right - rect.right;
		BounceX();
		isColliding = true;
	}
	if( rect.top < wall.top )
	{
		pos.y += wall.top - rect.top;
		BounceY();
		isColliding = true;
	}
	else if( rect.bottom > wall.bottom )
	{
		pos.y += wall.bottom - rect.bottom;
		BounceY();
		isColliding = true;
	}
	return isColliding;
}

void Ball::BounceX()
{
	vel.x = -vel.x;
}

void Ball::BounceY()
{
	vel.y = -vel.y;
}

RectF Ball::getRect()
{
	return RectF::FromCenter( pos, radius, radius );
}
