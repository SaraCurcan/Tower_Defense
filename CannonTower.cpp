#include "CannonTower.h"
#include "Utils.h"
#include <iostream>

CannonTower::CannonTower() : Tower(), damageArea(0.0) {}

CannonTower::CannonTower(int rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name, double damageArea)
    : Tower(rechargeTime, cost, life, damage, level, position, name) {
    Validator::validatePositive("damageArea", damageArea);
    this->damageArea = damageArea;
}

CannonTower::~CannonTower() {}

double CannonTower::getDamageArea() const { return damageArea; }

void CannonTower::setDamageArea(double damageArea) {
    Validator::validatePositive("damageArea", damageArea);
    this->damageArea = damageArea;
}

void CannonTower::upgrade() {
    level++;
    damage += 12;
    damageArea += 2;
    std::cout << "Cannon Tower updated to level " << level << std::endl;
    std::cout << "Damage area: " << damageArea << " damage: " << damage << std::endl;
}