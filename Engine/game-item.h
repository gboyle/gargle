#pragma once

#include "game-player.h"

#include "Graphics.h"

class Item {

  public:
    int x = 0;
    int y = 0;

    int dx = 0;
    int dy = 0;

    bool collected = false;

    static constexpr int w = 24;
    static constexpr int h = 24;

    void move();
    void checkCollision(Player &player, int &total_collected);
    void draw(Graphics &gfx) const;
};
