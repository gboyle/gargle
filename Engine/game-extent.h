#pragma once

struct Extent {

    int left;
    int right;
    int top;
    int bottom;

    Extent(int a_left, int a_right, int a_top, int a_bottom);

    bool overlaps(Extent const &rhs) const;
};