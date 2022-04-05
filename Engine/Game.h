/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Reticle.h"
#include "Player.h"
#include "Enemy.h"



class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

	static constexpr int lastLevel = 5;
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void ReInitialize();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	bool startMenuActive;
	bool intermissionActive;
	bool gameOver;
	bool gameWon;
	//allows for a pause so that player can see enemies spawn briefly before level begins
	bool nextLevelActivated;

	Reticle reticle;
	Player* player;
	Enemy** enemy;

	int level; //start at 0, go from 1 to 5 when start
	int current_enemies; //level * 2
	int num_alive;


	bool leftclick_buffer, shift_buffer, enter_buffer, reset_buffer;
	int player_x, player_y; //global player's coords (having an issue with other files accessing player.h)
	
};