#include "Skeleton.h"

Skeleton::Skeleton()
    : Enemy(50.0, 2.0, 3, 10.0, Vector2D{0,0}, 0.8,1.0) {}

Skeleton::Skeleton(double maxHealth, double speed, int reward, double damage, Vector2D position, double attackTime,double attackRange)
    : Enemy(maxHealth, speed, reward, damage, position, attackTime,attackRange) {}

Skeleton::~Skeleton() {}
Skeleton::Skeleton(Vector2D position)
    : Enemy(50.0, 2.0, 3, 10.0, position, 0.8, 1.0) {}
std::string Skeleton::getType() const { return "Skeleton"; }