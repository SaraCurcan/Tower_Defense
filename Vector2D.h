#pragma once
#include <cmath>
struct Vector2D {
    float x;
    float y;
public:
    double distanceTo(const Vector2D& obj) const {
        double dx=x-obj.x;
        double dy=y-obj.y;
        return std::sqrt(dx*dx + dy*dy);
    }

    Vector2D operator-(const Vector2D& obj) const {
        return {x - obj.x, y - obj.y};
    }

    Vector2D operator+(const Vector2D& obj) const {
        return {x + obj.x, y + obj.y};
    }
    Vector2D operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }
};
