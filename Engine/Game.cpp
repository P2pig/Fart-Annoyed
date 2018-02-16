/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball( Vec2( 300.0f + 16.0f, 300.0f ), Vec2( -300.0f, -300.0f ) ),
	wall( 0, 0, Graphics::ScreenWidth, Graphics::ScreenHeight ),
	soundPad( L"sounds\\arkpad.wav" ),
	soundBrick( L"sounds\\arkbrick.wav" ),
	pad( Vec2( 400.0f, 500.0f ), 50.0f, 15.0f )
{
	Vec2 topLeft( 40.0f, 40.0f );
	Color colors[4] = { Colors::Blue,Colors::Gray,Colors::Cyan,Colors::Green };
	for( int y = 0; y < nBricksDown; ++y )
	{
		for( int x = 0; x < nBricksAcross; x++ )
		{
			RectF rect( topLeft + Vec2( x*brickWidth, y*brickHeight ), brickWidth, brickHeight );
			bricks[x + (y * nBricksAcross)] = { rect, colors[y] };
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	ball.Update( dt );

	pad.Update( wnd.kbd, dt );
	pad.DoWallCollision( wall );

	bool isCollision = false;
	float currentColDistSq;
	int currentColIndex;
	for( int i = 0; i < nBricks; i++ )
	{
		if( bricks[i].CheckBallCollision( ball ) )
		{
			const float newColDistSq = (ball.getPosition() - bricks[i].GetCenter()).GetLengthSq();
			if( isCollision )
			{
				if( newColDistSq < currentColDistSq )
				{
					currentColDistSq = newColDistSq;
					currentColIndex = i;
				}
			}
			else
			{
				currentColDistSq = newColDistSq;
				currentColIndex = i;
				isCollision = true;
			}
		}
	}
	if( isCollision )
	{
		bricks[currentColIndex].ExcuteBallCollision( ball );
		soundBrick.Play();
	}

	if( pad.DoBallCollision( ball ) )
	{
		soundBrick.Play();
	}

	if( ball.DoWallCollision( wall ) )
	{
		// soundPad.Play();
	}
}

void Game::ComposeFrame()
{
	pad.Draw( gfx );
	for( Brick& b : bricks )
	{
		b.Draw( gfx );
	}
	ball.Draw( gfx );
}
