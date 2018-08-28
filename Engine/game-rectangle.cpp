
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
}

void MovableRectangle::limitPosition() {

    clamp(r, 0, 255);
    clamp(g, 0, 255);
    clamp(b, 0, 255);

    clamp(w, 1, max_width);
    clamp(h, 1, max_width);

    clamp(x, 0, Graphics::ScreenWidth - w);
    clamp(y, 0, Graphics::ScreenHeight - h);
}

void MovableRectangle::draw(Graphics &gfx) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            gfx.PutPixel(x + i, y + j, r, g, b);
        }
    }
}
