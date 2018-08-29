#pragma once

#include "Graphics.h"

class GameScore {

	int score = 0;

	static constexpr int x = 10;
	static constexpr int y = 10;
	static constexpr int h = 10;

public:

	GameScore& operator++();

	void draw(Graphics &gfx) const;
};
