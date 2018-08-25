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

Game::Game(MainWindow &wnd) : wnd(wnd), gfx(wnd) {}

void Game::Go() {
    gfx.BeginFrame();
    UpdateModel();
    ComposeFrame();
    gfx.EndFrame();
}

void Game::UpdateModel() {

    if (wnd.kbd.KeyIsPressed(0x52)) { dr = 1 - dr; }
    if (wnd.kbd.KeyIsPressed(0x47)) { dg = 1 - dg; }
    if (wnd.kbd.KeyIsPressed(0x42)) { db = 1 - db; }

    if (wnd.kbd.KeyIsPressed(VK_UP)) {
        if (!inhibit_up) {
            dy--;
            inhibit_up = true;
        }
    } else {
        inhibit_up = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
        if (!inhibit_down) {
            dy++;
            inhibit_down = true;
        }
    } else {
        inhibit_down = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
        if (!inhibit_left) {
            dx--;
            inhibit_left = true;
        }
    } else {
        inhibit_left = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        if (!inhibit_right) {
            dx++;
            inhibit_right = true;
        }
    } else {
        inhibit_right = false;
    }

    if (wnd.kbd.KeyIsPressed(VK_HOME)) {
        dx = 0;
        dy = 0;
    }

    if (wnd.kbd.KeyIsPressed(VK_PRIOR) && t < 100) {
        ++s;
        ++t;
    }

    if (wnd.kbd.KeyIsPressed(VK_NEXT) && s > 0) {
        --s;
        --t;
    }

    r += dr;
    g += dg;
    b += db;

    x += dx;
    y += dy;

    if (dx > max_speed) { dx = max_speed; }
    if (dx < -max_speed) { dx = -max_speed; }
    if (dy > max_speed) { dy = max_speed; }
    if (dy < -max_speed) { dy = -max_speed; }

    if (x + t > gfx.ScreenWidth) {
        x = gfx.ScreenWidth - t;
        dx = -dx;
    }

    if (x - t < 0) {
        x = t;
        dx = -dx;
    }

    if (y + t > gfx.ScreenHeight) {
        y = gfx.ScreenHeight - t;
        dy = -dy;
    }

    if (y - t < 0) {
        y = t;
        dy = -dy;
    }
}

void Game::ComposeFrame() {

    Color color(r, g, b);

    for (int i = s; i < t; i++) {
        gfx.PutPixel(x + i, y, color);
        gfx.PutPixel(x - i, y, color);
        gfx.PutPixel(x, y + i, color);
        gfx.PutPixel(x, y - i, color);
    }
}
