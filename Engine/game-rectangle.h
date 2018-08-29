#pragma once

#include "Graphics.h"
#include "MainWindow.h"

class MovableRectangle {

    int x = 0;
    int y = 0;
    int w = 10;
    int h = 10;
    int r = 128;
    int g = 128;
    int b = 128;

    static constexpr int speed = 10;
    static constexpr int max_width = 200;

  public:
    void checkKeys(MainWindow &wnd);
    void limitPosition();
    void draw(Graphics &gfx);
};
