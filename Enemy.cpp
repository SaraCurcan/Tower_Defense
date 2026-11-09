#include "Utils.h"
#include "Enemy.h"
#include "Tower.h"
#include <algorithm>

Enemy::Enemy()
    : health(100.0), speed(1.0), reward(10), damage(10.0), position(Vector2D(0, 0)), attackTime(1.0),remainingAttackTime(0.0),burnTimeLeft(0.0), burnDps(0.0) {}

Enemy::Enemy(double health, double speed, int reward, double damage, Vector2D position, double attackTime)
    : position(position),remainingAttackTime(0.0),burnTimeLeft(0.0), burnDps(0.0) {

    Validator::validatePositive("health", health);
    Validator::validatePositive("speed", speed);
    Validator::validatePositive("reward", reward);
    Validator::validatePositive("damage", damage);
    Validator::validateStrictPositive("attackTime", attackTime);

    this->health = health;
    this->speed = speed;
    this->reward = reward;
    this->damage = damage;
    this->attackTime=attackTime;
}

Enemy::~Enemy() {}

double Enemy::getHealth() const {
    return health;
}
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
Vector2D Enemy::getPosition() const {
    return position;
}



void Enemy::setHealth(double health) {
    Validator::validatePositive("health", health);
    this->health = health;
}
void Enemy::setPosition(Vector2D position) {
    this->position = position;
}

bool Enemy::isAlive() const {
    return health > 0;
}

void Enemy::takeDamage(double amount) {
    Validator::validatePositive("damageAmount", amount);
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

void Enemy::attack(Tower& targetTower) {
    if (!canAttack(targetTower))
        return;
    targetTower.takeDamage(damage);
    resetAttackCooldown();
}

bool Enemy::canAttack(const Tower& targetTower) const {
    return isAlive() && !targetTower.isDead() && isAttackReady();
}
bool Enemy::isAttackReady() const {
    return remainingAttackTime <= 0.0;
}
void Enemy::resetAttackCooldown() {
    remainingAttackTime = attackTime;
}
void Enemy::update(double dt) {
    Validator::validatePositive("dt", dt);

    remainingAttackTime -= dt;

    if (remainingAttackTime < 0.0) {
        remainingAttackTime = 0.0;
    }
    if (burnTimeLeft > 0.0) {
        double burnTime = std::min(dt, burnTimeLeft);
        takeDamage(burnDps * burnTime);
        burnTimeLeft -= burnTime;
    }
}
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