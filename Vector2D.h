#pragma once
#include <cmath>
#include <ostream>
struct Vector2D {
    float x = 0.0f;
    float y= 0.0f;
public:
    float length() const {
        return std::sqrt(x * x + y * y);
    }
    Vector2D normalized() const {
        float len = length();
        if (len == 0.0f) return {0.0f, 0.0f};
        return {x / len, y / len};
    }

    float distanceTo(const Vector2D& obj) const {
        return (*this - obj).length();
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
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};
