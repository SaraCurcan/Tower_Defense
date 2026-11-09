#pragma once
#include <vector>
#include <ostream>
#include "Vector2D.h"

class Path {
private:
    std::vector<Vector2D> waypoints;
public:
    explicit Path(const std::vector<Vector2D>& waypoints);

    std::size_t size() const;
    const Vector2D& getPoint(std::size_t index) const;
    const Vector2D& getStart() const;
    const Vector2D& getEnd() const;
    double totalLength() const;

    friend std::ostream& operator<<(std::ostream& os, const Path& path);
};