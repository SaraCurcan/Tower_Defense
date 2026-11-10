#include "Golem.h"

Golem::Golem()
    : Enemy(400.0, 0.5, 25, 50.0, Vector2D{0, 0}, 1.0, 0.0) {}

Golem::Golem(double maxHealth, double speed, int reward, double damage, Vector2D position)
    : Enemy(maxHealth, speed, reward, damage, position, 1.0, 0.0) {}

Golem::Golem(Vector2D position)
    : Enemy(400.0, 0.5, 25, 50.0, position, 1.0, 0.0) {}

Golem::~Golem() {}

bool Golem::canAttackTowers() const { return false; }

void Golem::takeHeavyHit() {
    takeDamage(maxHealth * hit_percent);
}

std::string Golem::getType() const { return "Golem"; }