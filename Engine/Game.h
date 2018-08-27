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

    int s = 10;
    int t = 20;

    Color color;
    int x = 255;
    int y = 255;

    int dx = 0;
    int dy = 0;
    const int dmax = 20;

    bool inhibit_right = false;
    bool inhibit_left = false;
    bool inhibit_up = false;
    bool inhibit_down = false;

	bool last_overlap = false;

    const int fixed_x0 = 400;
    const int fixed_y0 = 300;
    const int fixed_x1 = 200;
    const int fixed_y1 = 100;
    const int fixed_x2 = 500;
    const int fixed_y2 = 500;
    const int fixed_x3 = 700;
    const int fixed_y3 = 100;

    void checkKeys();
    static void limitSpeed(int &speed_x, int &speed_y, int max_speed);
    static void moveReticle(int &x, int &y, int &dx, int &dy);
    void limitPosition(int &pos_x, int &pos_y, int &speed_x, int speed_y,
                       int extent);
    static bool overlapTest(int x1, int y1, int x2, int y2, int extent);
    void drawReticle(int x, int y, Color const &c);

    static bool clamp(int &value, int min_val, int max_val);
    static int signOf(int value);
};