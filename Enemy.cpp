#include "Utils.h"
#include "Enemy.h"
#include "Path.h"
#include "Tower.h"
#include <algorithm>

Enemy::Enemy()
    : path(nullptr), nextWaypoint(0), reachedEnd(false),
      health(100.0), maxHealth(100.0), speed(1.0), reward(10), damage(10.0), attackRange(1.0),
      position(Vector2D{0, 0}), attackTime(1.0), remainingAttackTime(0.0),
      burnTimeLeft(0.0), burnDps(0.0) {}

Enemy::Enemy(double maxHealth, double speed, int reward, double damage, Vector2D position,
             double attackTime, double attackRange)
    : path(nullptr), nextWaypoint(0), reachedEnd(false), position(position),
      remainingAttackTime(0.0), burnTimeLeft(0.0), burnDps(0.0){

    Validator::validateStrictPositive("maxHealth", maxHealth);
    Validator::validatePositive("speed", speed);
    Validator::validatePositive("reward", reward);
    Validator::validatePositive("damage", damage);
    Validator::validateStrictPositive("attackTime", attackTime);
    Validator::validatePositive("attackRange", attackRange);

    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->speed = speed;
    this->reward = reward;
    this->damage = damage;
    this->attackTime=attackTime;
    this->attackRange = attackRange;
}

Enemy::~Enemy() {}
//getters / setters
double Enemy::getHealth() const {
    return health;
}
double Enemy::getMaxHealth() const { return maxHealth; }
double Enemy::getSpeed() const {
    return speed;
}
int Enemy::getReward() const {
    return reward;
}
double Enemy::getDamage() const {
    return damage;
}
double Enemy::getAttackTime() const {
    return attackTime;
}

double Enemy::getAttackRange() const { return attackRange; }

Vector2D Enemy::getPosition() const {
    return position;
}

void Enemy::setHealth(double health) {
    Validator::validatePositive("health", health);
    this->health = std::min(health, maxHealth);
}
void Enemy::setPosition(Vector2D position) {
    this->position = position;
}

bool Enemy::isAlive() const {
    return health > 0;
}

// attack logic
void Enemy::takeDamage(double amount) {
    Validator::validatePositive("damageAmount", amount);
    health = std::max(0.0, health - amount);
}

void Enemy::attack(Tower& targetTower) {
    if (!canAttack(targetTower))
        return;
    targetTower.takeDamage(damage);
    resetAttackCooldown();
}

bool Enemy::canAttackTowers() const { return true; }
bool Enemy::canAttack(const Tower& targetTower) const {
    return canAttackTowers() && isAlive() && !targetTower.isDead() && isAttackReady()
    && position.distanceTo(targetTower.getPosition()) <= attackRange;
}

bool Enemy::isAttackReady() const {
    return remainingAttackTime <= 0.0;
}
void Enemy::resetAttackCooldown() {
    remainingAttackTime = attackTime;
}

void Enemy::heal(double amount) {
    Validator::validatePositive("healAmount", amount);
    health = std::min(maxHealth, health + amount);
}

Tower* Enemy::findTowerInRange(std::vector<std::unique_ptr<Tower>>& towers) const {
    Tower* best = nullptr;
    double bestDistance = attackRange;
    for (auto& tower : towers) {
        if (tower->isDead()) continue;
        double d = position.distanceTo(tower->getPosition());
        if (d <= bestDistance) {
            bestDistance = d;
            best = tower.get();
        }
    }
    return best;
}
// burn and heavy hit
void Enemy::applyBurn(double dps, double duration) {
    Validator::validatePositive("burnDps", dps);
    Validator::validatePositive("burnDuration", duration);
    burnDps = dps;
    burnTimeLeft = duration;
}
bool Enemy::isBurning() const {
    return burnTimeLeft > 0.0;
}
void Enemy::takeHeavyHit() {
    takeDamage(health);
}

//moving
void Enemy::setPath(const Path& path) {
    this->path = &path;
    position = path.getStart();
    nextWaypoint = 1;
    reachedEnd = false;
}

bool Enemy::hasReachedEnd() const { return reachedEnd; }

void Enemy::move(double dt) {
    Validator::validatePositive("dt", dt);
    if (path == nullptr || reachedEnd || !isAlive())
        return;

    double step = speed * dt;
    while (step > 0.0 && !reachedEnd) {
        Vector2D target = path->getPoint(nextWaypoint);
        double dist = position.distanceTo(target);

        if (dist <= step) {
            position = target;
            step -= dist;
            nextWaypoint++;
            if (nextWaypoint >= path->size())
                reachedEnd = true;
        } else {
            position = position + (target - position).normalized() * static_cast<float>(step);
            step = 0.0;
        }
    }
}
 //update
void Enemy::tickTimers(double dt) {
    remainingAttackTime = std::max(0.0, remainingAttackTime - dt);
    if (burnTimeLeft > 0.0) {
        double burnTime = std::min(dt, burnTimeLeft);
        takeDamage(burnDps * burnTime);
        burnTimeLeft -= burnTime;
    }
}

void Enemy::update(double dt, std::vector<std::unique_ptr<Tower>>& towers) {
    Validator::validatePositive("dt", dt);
    tickTimers(dt);
    if (!isAlive() || reachedEnd)
        return;

    Tower* target = canAttackTowers() ? findTowerInRange(towers) : nullptr;
    if (target != nullptr)
        attack(*target);
    else
        move(dt);
}

//printing
void Enemy::print(std::ostream& os) const {
    os << getType() << " at " << position
       << " | hp " << health << "/" << maxHealth
       << " | speed " << speed << " | dmg " << damage
       << " | atkRange " << attackRange
       << (isBurning() ? " | burning" : "")
       << (reachedEnd ? " | AT TREASURE" : "");
}

std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
    enemy.print(os);
    return os;
}