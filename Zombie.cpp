#include "Zombie.h"
#include "Tower.h"
#include <iostream>
#include "Utils.h"

Zombie::Zombie()
    : Enemy(100.0, 1.5, 5, 20.0, Vector2D(0, 0), 1.0),  maxHealth(100.0) {}

Zombie::Zombie(double health, double speed, int reward, double damage, Vector2D position, double attackTime, double maxHealth)
    : Enemy(health, speed, reward, damage, position, attackTime), maxHealth(maxHealth) {
    Validator::validateStrictPositive("maxHealth", maxHealth);
    checkLife();
}
Zombie::~Zombie() {}

void Zombie::move(const Vector2D& targetPosition) {
    position = position + (targetPosition - position) * (speed * 0.01);
}

void Zombie::checkLife() {
    if (health > maxHealth) {
        health = maxHealth;
    }
}

void Zombie::attack(Tower& targetTower) {
    if (!canAttack(targetTower))
        return;
    double actualDamage = targetTower.takeDamage(damage);
    double regeneratedHealth = actualDamage * 0.20;
    health += regeneratedHealth;
    checkLife();
    resetAttackCooldown();
}