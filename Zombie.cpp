#include "Zombie.h"
#include "Tower.h"
#include <iostream>

Zombie::Zombie()
    : Enemy(100.0, 1.5, 5, 20.0, Vector2D(0, 0), 1.0),  maxHealth(100.0) {}

Zombie::Zombie(double health, double speed, int reward, double damage, Vector2D position, double attackTime, double maxHealth)
    : Enemy(health, speed, reward, damage, position, attackTime), maxHealth(maxHealth) {}
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
    targetTower.takeDamage(this->damage);
    double stolenHealth = this->damage * 0.25;
    this->health += stolenHealth;

    checkLife();
}