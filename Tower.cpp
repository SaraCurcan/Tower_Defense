#include <iostream>
#include <string>
#include "Tower.h"
#include "Utils.h"
Tower::Tower():rechargeTime(0),cost(0),life(0.0), damage(0.0), level(1), position(0.0, 0.0), name("DefaultTower") {}
Tower::Tower(int rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name) {
    Validator::validatePositive("rechargeTime",rechargeTime);
    Validator::validatePositive("cost",cost);
    Validator::validatePositive("life",life);
    Validator::validatePositive("damage",damage);
    Validator::validateStrictPositive("level",level);

    this->rechargeTime = rechargeTime;
    this->cost = cost;
    this->life = life;
    this->damage = damage;
    this->level = level;
    this->position = position;
    this->name = name;
}

Tower::~Tower() {}

int Tower::getRechargeTime() const { return rechargeTime; }
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
    if (rechargeTime > 0) {
        rechargeTime -= dt;
        if (rechargeTime < 0)
            rechargeTime = 0;
    }
}

bool Tower::isRecharged() const {
    return rechargeTime <= 0;
}

void Tower::takeDamage(double amount) {
    Validator::validatePositive("damageAmount", amount);
    life -= amount;
    if (life < 0) {
        life = 0;
    }
}