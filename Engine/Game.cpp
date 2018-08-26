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

    checkKeys();

    limitSpeed(dx, dy, dmax);
    moveReticle(x, y, dx, dy);
    limitPosition(x, y, dx, dy, t);

    bool overlapping = overlapTest(x, y, fixed_x0, fixed_y0, t) ||
                       overlapTest(x, y, fixed_x1, fixed_y1, t) ||
                       overlapTest(x, y, fixed_x2, fixed_y2, t) ||
                       overlapTest(x, y, fixed_x3, fixed_y3, t);

    if (overlapping) {
        color = Color(255, 0, 0);
    } else {
        color = Color(0, 255, 0);
    }
}

void Game::ComposeFrame() {

    drawReticle(fixed_x0, fixed_y0, Color(255, 255, 255));
    drawReticle(fixed_x1, fixed_y1, Color(255, 255, 255));
    drawReticle(fixed_x2, fixed_y2, Color(255, 255, 255));
    drawReticle(fixed_x3, fixed_y3, Color(255, 255, 255));

    drawReticle(x, y, color);
}

void Game::checkKeys() {

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
}

void Game::limitSpeed(int &speed_x, int speed_y, int max_speed) {

    clamp(speed_x, -max_speed, max_speed);
    clamp(speed_y, -max_speed, max_speed);
}

void Game::moveReticle(int &x, int &y, int &dx, int &dy) {

    x += dx;
    y += dy;
}

void Game::limitPosition(int &pos_x, int &pos_y, int &speed_x, int speed_y,
                         int extent) {

    if (clamp(pos_x, extent, gfx.ScreenWidth - extent)) { dx = -dx; }
    if (clamp(pos_y, extent, gfx.ScreenHeight - extent)) { dy = -dy; }
}

void Game::drawReticle(int x, int y, Color const &c) {

    for (int i = s; i < t; i++) {
        gfx.PutPixel(x + i, y, c);
        gfx.PutPixel(x - i, y, c);
        gfx.PutPixel(x, y + i, c);
        gfx.PutPixel(x, y - i, c);
    }
}

bool Game::overlapTest(int x1, int y1, int x2, int y2, int extent) {

    if (x1 + extent < x2 - extent) { return false; }
    if (x2 + extent < x1 - extent) { return false; }
    if (y1 + extent < y2 - extent) { return false; }
    if (y2 + extent < y1 - extent) { return false; }

    return true;
}

bool Game::clamp(int &value, int min_val, int max_val) {

    if (value < min_val) {
        value = min_val;
        return true;
    }

    if (value > max_val) {
        value = max_val;
        return true;
    }

    return false;
}
