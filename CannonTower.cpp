#include "CannonTower.h"
#include "Utils.h"
#include "Enemy.h"
#include <iostream>

CannonTower::CannonTower()
    : Tower(5.0, 250, 300.0, 0.0, 3.5, Vector2D{0, 0}, "CannonTower"),
      damageArea(1.5) {}

CannonTower::CannonTower(double rechargeTime, int cost, double maxLife, double damage, double range,
                         Vector2D position, const std::string& name, double damageArea)
    : Tower(rechargeTime, cost, maxLife, damage, range, position, name) {
    Validator::validatePositive("damageArea", damageArea);
    this->damageArea = damageArea;
}

CannonTower::CannonTower(Vector2D position)
    : Tower(5.0, 250, 300.0, 0.0, 3.5, position, "CannonTower"),
      damageArea(1.5) {}

CannonTower::~CannonTower() {}

double CannonTower::getDamageArea() const { return damageArea; }

void CannonTower::setDamageArea(double damageArea) {
    Validator::validatePositive("damageArea", damageArea);
    this->damageArea = damageArea;
}

void CannonTower::fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>& enemies) {
    Vector2D impact = target.getPosition();
    for (auto& enemy : enemies) {
        if (enemy->isAlive() && impact.distanceTo(enemy->getPosition()) <= damageArea)
            enemy->takeHeavyHit();
    }
}

void CannonTower::applyUpgrade() {
    damageArea += 0.5;
    setRechargeTime(getRechargeTime() * 0.90);
}

void CannonTower::print(std::ostream& os) const {
    Tower::print(os);
    os << " | area " << damageArea;
}