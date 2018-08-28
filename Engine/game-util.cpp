
#include "game-util.h"

bool inside(int value, int min_val, int max_val) {

    return min_val <= value && value <= max_val;
}

bool clamp(int &value, int min_val, int max_val) {

    if (value < min_val) {
        value = min_val;
        return true;
    }

    if (value > max_val) {
        value = max_val;
        return true;
    }

    return false;
}
