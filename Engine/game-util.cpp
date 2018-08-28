
#include "game-util.h"

#include <utility>

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


bool order(int &value0, int &value1) {

	if (value0 <= value1) {
		return false;
	}

	std::swap(value0, value1);

	return true;
}

int sign(int value) {

    if (value > 0) {
        return 1;
    } else if (value == 0) {
        return 0;
    } else {
        return -1;
    }
}