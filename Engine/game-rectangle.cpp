
#include "game-rectangle.h"
#include "game-util.h"

MovableRectangle::MovableRectangle(std::mt19937 &gen) { relocate(gen); }

void MovableRectangle::relocate(std::mt19937 &gen) {

    std::uniform_int_distribution<> dis_x(0, Graphics::ScreenWidth - w);
    std::uniform_int_distribution<> dis_y(0, Graphics::ScreenHeight - h);
    std::uniform_int_distribution<> dis_c(32, 255);

    x = dis_x(gen);
    y = dis_y(gen);
    r = dis_c(gen);
    g = dis_c(gen);
    b = dis_c(gen);
}

Extent MovableRectangle::extent() const { return {x, x + w, y, y + h}; }

void MovableRectangle::draw(Graphics &gfx) const {

    gfx.DrawRectWH(x, y, w, h, Color(r, g, b));
}
