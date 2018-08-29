#pragma once

#include "Graphics.h"
#include "MainWindow.h"

#include "game-extent.h"

#include <random>

class MovableRectangle {

    int x = 0;
    int y = 0;
    int r = 128;
    int g = 128;
    int b = 128;

	static constexpr int w = 10;
	static constexpr int h = 10;

  public:    
    
	explicit MovableRectangle(std::mt19937 &gen);

	void relocate(std::mt19937 &gen);

	Extent extent() const;

    void draw(Graphics &gfx) const;
};
