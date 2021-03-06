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

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "game-score.h"
#include "game-item.h"
#include "game-player.h"
#include "game-rectangle.h"

#include <random>

class Game {
  public:
    explicit Game(MainWindow &wnd);
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    void Go();

  private:
    void ComposeFrame();
    void UpdateModel();
    /********************************/
    /*  User Functions              */
    /********************************/
  private:
    MainWindow &wnd;
    Graphics gfx;
    /********************************/
    /*  User Variables              */
    /********************************/

	std::random_device rd;
	std::mt19937 gen;

    bool isStarted = false;
    bool isFinished = false;

    int killed = 0;

	GameScore score;
    std::vector<Player> players;
    std::vector<Item> items;
	std::vector<MovableRectangle> rectangles;

    void drawGameOver(int x, int y);
    void drawTitle(int x, int y);
};