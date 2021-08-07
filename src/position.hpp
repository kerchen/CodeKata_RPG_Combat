#ifndef POSITION_GUARD_HPP
#define POSITION_GUARD_HPP

#include <cmath>

struct Position {
    double value { 0.0 };

    double getDistance(Position const & other) const { return abs(other.value - value); }
};

#endif // POSITION_GUARD_HPP
