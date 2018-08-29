#pragma once

#include "Graphics.h"
#include "MainWindow.h"

#include "game-extent.h"

#include <random>

class Player {

    int x = 0;
    int y = 0;

    int score = 0;

    static constexpr int w = 20;
    static constexpr int h = 20;
    static constexpr int speed = 3;

  public:
    explicit Player(std::mt19937 &gen);

    void checkKeys(MainWindow const &wnd);
    void limitPosition();
    void collectItem();

    Extent extent() const;

    void draw(Graphics &gfx) const;
};
