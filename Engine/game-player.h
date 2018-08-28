#pragma once

#include "Graphics.h"
#include "MainWindow.h"

class Player {

  public:
    int x = 0;
    int y = 0;

    int score = 0;

    static constexpr int w = 20;
    static constexpr int h = 20;
    static constexpr int speed = 3;

    void checkKeys(MainWindow &wnd);
    void limitPosition();
    void draw(Graphics &gfx) const;
};
