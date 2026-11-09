#include "Path.h"
#include "Exceptions.h"

Path::Path(const std::vector<Vector2D>& waypoints) : waypoints(waypoints) {
    if (waypoints.size() < 2)
        throw InvalidPath("a path needs at least 2 waypoints");
}

std::size_t Path::size() const { return waypoints.size(); }

const Vector2D& Path::getPoint(std::size_t index) const {
    if (index >= waypoints.size())
        throw InvalidPath("waypoint index " + std::to_string(index) + " out of range");
    return waypoints[index];
}

const Vector2D& Path::getStart() const { return waypoints.front(); }
const Vector2D& Path::getEnd() const { return waypoints.back(); }

double Path::totalLength() const {
    double total = 0.0;
    for (std::size_t i = 1; i < waypoints.size(); i++)
        total += waypoints[i - 1].distanceTo(waypoints[i]);
    return total;
}

std::ostream& operator<<(std::ostream& os, const Path& path) {
    os << "Path:";
    for (const auto& p : path.waypoints)
        os << " " << p;
    return os;
}