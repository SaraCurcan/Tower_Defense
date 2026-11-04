#include "GunTower.h"
#include "Utils.h"
#include <iostream>

GunTower::GunTower() : Tower(){}
GunTower::GunTower(double rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name)
    : Tower(rechargeTime, cost, life, damage, level, position, name) {
}

void GunTower::upgrade() {
    level++;
    damage+=5.0;
    std::cout<<"GunTower was upgraded to level "<<level<<std::endl;
    std::cout<<"Shooter damage: "<<damage<<std::endl;
}

void GunTower::attack(Enemy& enemy) {
    if (!canAttack(enemy)) {
        return;
    }
    enemy.takeDamage(this->damage);
    resetCooldown();
}

GunTower::~GunTower(){}
