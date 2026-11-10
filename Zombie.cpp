#include "Zombie.h"
#include "Tower.h"
#include "Utils.h"

Zombie::Zombie()
    : Enemy(100.0, 1.0, 5, 20.0, Vector2D{0, 0}, 1.0, 1.0) {}

Zombie::Zombie(double maxHealth, double speed, int reward, double damage, Vector2D position,
               double attackTime, double attackRange)
    : Enemy(maxHealth, speed, reward, damage, position, attackTime, attackRange) {}

Zombie::~Zombie() {}

void Zombie::attack(Tower& targetTower) {
    if (!canAttack(targetTower))
        return;
    double actualDamage = targetTower.takeDamage(damage);
    heal(actualDamage * heal_percent);
    resetAttackCooldown();
}

Zombie::Zombie(Vector2D position)
    : Enemy(100.0, 1.0, 5, 20.0, position, 1.0, 1.0) {}

std::string Zombie::getType() const { return "Zombie"; }