#pragma once
#include <cmath>
struct Vector2D {
    float x;
    float y;
public:
    double distanceTo(const Vector2D& other) const {
        double dx=x-other.x;
        double dy=y-other.y;
        return std::sqrt(dx*dx + dy*dy);
    }
};
