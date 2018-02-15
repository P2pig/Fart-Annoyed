#include "Paddle.h"

Paddle::Paddle( const Vec2 & pos_in, float halfWidth_in, float halfHeight_in )
	:
	pos( pos_in ),
	halfWidth( halfWidth_in ),
	halfHeight( halfHeight_in )
{
}

void Paddle::Update( Keyboard & kbd, float dt )
{
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		pos.x += speed * dt;
	}
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		pos.x -= speed * dt;
	}
}

void Paddle::DoWallCollision( const RectF & wall )
{
	const RectF rect = getRect();
	if( rect.left < wall.left )
	{
		pos.x += wall.left - rect.left;
	}
	else if( rect.right > wall.right )
	{
		pos.x += wall.right - rect.right;
	}
}

bool Paddle::DoBallCollision( Ball & ball ) const
{
	const RectF rect = getRect();
	if( rect.isOverLapping( ball.getRect() ) && ball.getVelocity().y > 0.0f )
	{
		ball.BounceY();
		return true;
	}
	return false;
}

void Paddle::Draw( Graphics & gfx ) const
{
	RectF rect = getRect();
	gfx.DrawRect( rect, wingColor );
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect( rect, color );
}

RectF Paddle::getRect() const
{
	return RectF::FromCenter( pos, halfWidth, halfHeight );
}
