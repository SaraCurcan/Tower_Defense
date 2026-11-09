#include "ArcherTower.h"
#include "Utils.h"
#include "Enemy.h"
#include <iostream>

ArcherTower::ArcherTower()
    : Tower(1.5, 150, 150.0, 10.0, 4.0, Vector2D{0, 0}, "ArcherTower"),
      burnDps(5.0), burnDuration(3.0) {}

ArcherTower::ArcherTower(double rechargeTime, int cost, double maxLife, double damage, double range,
                         Vector2D position, const std::string& name, double burnDps, double burnDuration)
    : Tower(rechargeTime, cost, maxLife, damage, range, position, name) {
    Validator::validatePositive("burnDps", burnDps);
    Validator::validatePositive("burnDuration", burnDuration);
    this->burnDps = burnDps;
    this->burnDuration = burnDuration;
}


ArcherTower::~ArcherTower(){}

double ArcherTower::getBurnDuration() const { return burnDuration; }
void ArcherTower::setBurnDuration(double burnDurations) {
    Validator::validatePositive("burnDuration", burnDurations);
    this->burnDuration = burnDurations;
}

double ArcherTower::getBurnDps() const { return burnDps; }

ArcherTower::ArcherTower(Vector2D position)
    : Tower(1.5, 150, 150.0, 10.0, 4.0, position, "ArcherTower"),
      burnDps(5.0), burnDuration(3.0) {}

void ArcherTower::fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>&) {
    target.takeDamage(damage);
    target.applyBurn(burnDps, burnDuration);
}

void ArcherTower::applyUpgrade() {
    damage += 3.0;
    burnDps += 2.0;
    burnDuration += 0.5;
}

void ArcherTower::print(std::ostream& os) const {
    Tower::print(os);
    os << " | burn " << burnDps << " dps x " << burnDuration << "s";
}