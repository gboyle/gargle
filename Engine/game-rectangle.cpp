
#include "game-rectangle.h"
#include "game-util.h"

void MovableRectangle::checkKeys(MainWindow &wnd) {

    if (wnd.kbd.KeyIsPressed('A')) { x -= speed; }
    if (wnd.kbd.KeyIsPressed('D')) { x += speed; }
    if (wnd.kbd.KeyIsPressed('W')) { y -= speed; }
    if (wnd.kbd.KeyIsPressed('S')) { y += speed; }

    if (wnd.kbd.KeyIsPressed('R')) { w += 2; }
    if (wnd.kbd.KeyIsPressed('F')) { w -= 2; }
    if (wnd.kbd.KeyIsPressed('T')) { h += 2; }
    if (wnd.kbd.KeyIsPressed('G')) { h -= 2; }

    if (wnd.kbd.KeyIsPressed('Y')) { r += 8; }
    if (wnd.kbd.KeyIsPressed('H')) { r -= 8; }
    if (wnd.kbd.KeyIsPressed('U')) { g += 8; }
    if (wnd.kbd.KeyIsPressed('J')) { g -= 8; }
    if (wnd.kbd.KeyIsPressed('I')) { b += 8; }
    if (wnd.kbd.KeyIsPressed('K')) { b -= 8; }

    if (wnd.mouse.LeftIsPressed()) {
        w = wnd.mouse.GetPosX() - x;
        h = wnd.mouse.GetPosY() - y;
    }
}

void MovableRectangle::limitPosition() {

    clamp(r, 0, 255);
    clamp(g, 0, 255);
    clamp(b, 0, 255);

    clamp(w, -max_width, max_width);
    clamp(h, -max_width, max_width);

    if (w >= 0) {
        clamp(x, 0, Graphics::ScreenWidth - w);
    } else {
        clamp(x, -w, Graphics::ScreenWidth);
    }

    if (h >= 0) {
        clamp(y, 0, Graphics::ScreenHeight - h);
    } else {
        clamp(y, -h, Graphics::ScreenHeight);
    }
}

void MovableRectangle::draw(Graphics &gfx) {

    gfx.DrawRectWH(x, y, w, h, Color(r, g, b));
}
