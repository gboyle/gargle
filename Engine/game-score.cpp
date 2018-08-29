
#include "game-score.h"
#include "game-util.h"

GameScore &GameScore::operator++() {

    ++score;
    return *this;
}

void GameScore::draw(Graphics &gfx) const {

    const int delta = 5;
    int w = (score + 1) * delta;

    clamp(w, 0, Graphics::ScreenWidth - x);

    gfx.DrawRectWH(x, y, w, h, Color(0, 0, 255));
}
