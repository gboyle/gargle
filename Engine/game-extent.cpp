
#include "game-extent.h"

Extent::Extent(int a_left, int a_right, int a_top, int a_bottom)
    : left(a_left), right(a_right), top(a_top), bottom(a_bottom) {}

bool Extent::overlaps(Extent const &rhs) const {

    bool distinct = rhs.right < left || right < rhs.left || rhs.bottom < top ||
                    bottom < rhs.top;

    return !distinct;
}
