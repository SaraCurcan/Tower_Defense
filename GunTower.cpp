#include "GunTower.h"
#include <iostream>
#include "Enemy.h"

GunTower::GunTower()
    : Tower(1.0, 100, 200.0, 20.0, 3.0, Vector2D{0, 0}, "GunTower") {}

GunTower::GunTower(double rechargeTime, int cost, double maxLife, double damage, double range,
                   Vector2D position, const std::string& name)
    : Tower(rechargeTime, cost, maxLife, damage, range, position, name) {}

GunTower::GunTower(Vector2D position)
    : Tower(1.0, 100, 200.0, 20.0, 3.0, position, "GunTower") {}

GunTower::~GunTower(){}

void GunTower::fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>&) {
    target.takeDamage(damage);
}

void GunTower::applyUpgrade() {
    damage += 5.0;
}