#include <iostream>
#include <string>
#include<algorithm>
#include "Tower.h"
#include "Utils.h"
Tower::Tower():rechargeTime(0.0),remainingRecharge(0.0),cost(0),life(0.0), damage(0.0), level(1), position(0.0, 0.0), name("DefaultTower") {}
Tower::Tower(double rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name) {
    Validator::validateStrictPositive("rechargeTime",rechargeTime);
    Validator::validatePositive("cost",cost);
    Validator::validateStrictPositive("life", life);
    Validator::validatePositive("damage",damage);
    Validator::validateStrictPositive("level",level);

    this->rechargeTime = rechargeTime;
    this->remainingRecharge=0.0;
    this->cost = cost;
    this->life = life;
    this->damage = damage;
    this->level = level;
    this->position = position;
    this->name = name;
}

Tower::~Tower() {}

double Tower::getRechargeTime() const { return rechargeTime; }
int Tower::getCost() const { return cost; }
int Tower::getLevel() const { return level; }

Vector2D Tower::getPosition() const { return this->position; }
void Tower::setPosition( Vector2D position) { this->position = position; }

double Tower::getLife() const { return life; }
std::string Tower::getName() const { return name; }

bool Tower::isDead() const {
    return life<=0;
}

void Tower::update(double dt) {
    Validator::validatePositive("dt", dt);

    if (remainingRecharge > 0.0) {
        remainingRecharge -= dt;

        if (remainingRecharge < 0.0) {
            remainingRecharge = 0.0;
        }
    }
}

bool Tower::isRecharged() const {
    return remainingRecharge <= 0.0;
}

double Tower::takeDamage(double amount) {
    Validator::validatePositive("damageAmount", amount);
    double actualDamage = std::min(life, amount);
    life -= actualDamage;
    return actualDamage;
}

void Tower::resetCooldown() {
    remainingRecharge = rechargeTime;
}

double Tower::getRemainingRecharge() const {
    return remainingRecharge;
}

bool Tower::canAttack(const Enemy& enemy) const {
    return !isDead() && isRecharged() && enemy.isAlive();
}