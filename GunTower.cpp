#include "GunTower.h"
#include "Utils.h"
#include <iostream>

GunTower::GunTower() : Tower(), bulletSpeed(0.0) {}
GunTower::GunTower(int rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name, double bulletSpeed)
    : Tower(rechargeTime, cost, life, damage, level, position, name) {

    Validator::validatePositive("bulletSpeed", bulletSpeed);
    this->bulletSpeed = bulletSpeed;
}

double GunTower::getBulletSpeed() const { return bulletSpeed; }
void  GunTower::setBulletSpeed(double bSpeed) {
    Validator::validatePositive("bulletSpeed", bSpeed);
    bulletSpeed = bSpeed;
}

void GunTower::upgrade() {
    level++;
    damage+=5.0;
    bulletSpeed+=5;
    std::cout<<"GunTower was upgraded to level "<<level<<std::endl;
    std::cout<<"Bullet speed: "<<bulletSpeed<<" Shooter damage: "<<damage<<std::endl;
}

GunTower::~GunTower(){}
