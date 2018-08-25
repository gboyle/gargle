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

    if (wnd.kbd.KeyIsPressed(0x52)) { red = (red + speed) & 0xFF; }
    if (wnd.kbd.KeyIsPressed(0x47)) { green = (green + speed) & 0xFF; }
    if (wnd.kbd.KeyIsPressed(0x42)) { blue = (blue + speed) & 0xFF; }
    if (wnd.kbd.KeyIsPressed(VK_UP)) { y = (sy + y - speed) % sy; }
    if (wnd.kbd.KeyIsPressed(VK_DOWN)) { y = (sy + y + speed) % sy; }
    if (wnd.kbd.KeyIsPressed(VK_LEFT)) { x = (sx + x - speed) % sx; }
    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) { x = (sx + x + speed) % sx; }

    if (wnd.kbd.KeyIsPressed(VK_PRIOR)) {
        ++a;
        ++b;
    }

    if (wnd.kbd.KeyIsPressed(VK_NEXT)) {
        --a;
        --b;
    }
}

void Game::ComposeFrame() {

    Color color(red, green, blue);

    for (int i = a; i < b; i++) {
        gfx.PutPixel(x + i, y, color);
        gfx.PutPixel(x - i, y, color);
        gfx.PutPixel(x, y + i, color);
        gfx.PutPixel(x, y - i, color);
    }
}
