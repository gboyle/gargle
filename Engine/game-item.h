#pragma once

#include "game-player.h"

#include "Graphics.h"

#include <random>

class Item {

    int x = 0;
    int y = 0;

    int dx = 0;
    int dy = 0;

    static constexpr int w = 24;
    static constexpr int h = 24;

  public:
    explicit Item(std::mt19937 &gen);

    void move();    

    Extent extent() const;

    void draw(Graphics &gfx) const;
};
