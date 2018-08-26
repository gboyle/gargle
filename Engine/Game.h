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

class Game {
  public:
    Game(MainWindow &wnd);
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

    const int max_speed = 10;

    int s = 10;
    int t = 20;

    int x = 255;
    int y = 255;

    int dx = 0;
    int dy = 0;

    bool inhibit_right = false;
    bool inhibit_left = false;
    bool inhibit_up = false;
    bool inhibit_down = false;

    Color color;
    const int stationary_x = 400;
    const int stationary_y = 300;

    void drawReticle(int x, int y, Color const &c);
};