#include "Skeleton.h"

Skeleton::Skeleton()
    : Enemy(50.0, 2.0, 3, 10.0, Vector2D(0, 0), 0.8) {}

Skeleton::Skeleton(double health, double speed, int reward, double damage, Vector2D position, double attackTime)
    : Enemy(health, speed, reward, damage, position, attackTime) {}

Skeleton::~Skeleton() {}

void Skeleton::move(const Vector2D& targetPosition) {
    position = position + (targetPosition - position) * (speed * 0.01);
}