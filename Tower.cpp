#include "Tower.h"
#include "Enemy.h"
#include "Utils.h"
#include <algorithm>

Tower::Tower(double rechargeTime, int cost, double maxLife, double damage, double range,
             Vector2D position, const std::string& name)
    : remainingRecharge(0.0), level(1), position(position), name(name) {
    Validator::validateStrictPositive("rechargeTime", rechargeTime);
    Validator::validatePositive("cost", cost);
    Validator::validateStrictPositive("maxLife", maxLife);
    Validator::validatePositive("damage", damage);
    Validator::validateStrictPositive("range", range);

    this->rechargeTime = rechargeTime;
    this->cost = cost;
    this->maxLife = maxLife;
    this->life = maxLife;
    this->damage = damage;
    this->range = range;
}

double Tower::getRechargeTime() const { return rechargeTime; }
double Tower::getRemainingRecharge() const { return remainingRecharge; }
int Tower::getCost() const { return cost; }
int Tower::getUpgradeCost() const { return cost / 2 * level; }
int Tower::getLevel() const { return level; }
double Tower::getLife() const { return life; }
double Tower::getMaxLife() const { return maxLife; }
double Tower::getRange() const { return range; }
Vector2D Tower::getPosition() const { return position; }
void Tower::setPosition(Vector2D newPosition) { position = newPosition; }
const std::string& Tower::getName() const { return name; }

bool Tower::isDead() const { return life <= 0; }
bool Tower::isRecharged() const { return remainingRecharge <= 0.0; }
void Tower::resetCooldown() { remainingRecharge = rechargeTime; }

void Tower::setRechargeTime(double newRechargeTime) {
    Validator::validateStrictPositive("rechargeTime", newRechargeTime);
    rechargeTime = newRechargeTime;
}

bool Tower::isInRange(const Enemy& enemy) const {
    return position.distanceTo(enemy.getPosition()) <= range;
}

double Tower::takeDamage(double amount) {
    Validator::validatePositive("damageAmount", amount);
    double actualDamage = std::min(life, amount);
    life -= actualDamage;
    return actualDamage;
}

Enemy* Tower::findTarget(std::vector<std::unique_ptr<Enemy>>& enemies) const {
    Enemy* best = nullptr;
    double bestDistance = range;
    for (auto& enemy : enemies) {
        if (!enemy->isAlive()) continue;
        double d = position.distanceTo(enemy->getPosition());
        if (d <= bestDistance) {
            bestDistance = d;
            best = enemy.get();
        }
    }
    return best;
}

void Tower::update(double dt, std::vector<std::unique_ptr<Enemy>>& enemies) {
    Validator::validatePositive("dt", dt);
    if (isDead()) return;

    if (remainingRecharge > 0.0)
        remainingRecharge = std::max(0.0, remainingRecharge - dt);

    if (!isRecharged()) return;

    Enemy* target = findTarget(enemies);
    if (target == nullptr) return;

    fire(*target, enemies);
    resetCooldown();
}

void Tower::upgrade() {
    if (level >= MAX_LEVEL)
        throw MaxLevelReached(name, MAX_LEVEL);
    level++;
    applyUpgrade();
}

void Tower::print(std::ostream& os) const {
    os << name << " [lvl " << level << "] at " << position
       << " | life " << life << "/" << maxLife
       << " | dmg " << damage << " | range " << range
       << " | reload " << remainingRecharge << "/" << rechargeTime;
}

std::ostream& operator<<(std::ostream& os, const Tower& tower) {
    tower.print(os);
    return os;
}