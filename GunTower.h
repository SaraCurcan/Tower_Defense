#pragma once
#include <iostream>
#include "Tower.h"

class GunTower : public Tower {
private:
    double bulletSpeed;
public:
    GunTower();
    GunTower(int rechargeTime,int cost, double life, double damage, int level, Vector2D position, std::string name, double bulletSpeed);
    GunTower(const GunTower& obj)=default;
    GunTower& operator=(const GunTower& obj)=default;

    // void attack() override;
    void upgrade() override;
    double getBulletSpeed() const;
    void setBulletSpeed(double bSpeed);
    ~GunTower() override;
};