#pragma once
#include <iostream>
#include "Tower.h"

class GunTower : public Tower {
public:
    GunTower();
    GunTower(double rechargeTime,int cost, double life, double damage, int level, Vector2D position, std::string name);
    GunTower(const GunTower& obj)=default;
    GunTower& operator=(const GunTower& obj)=default;

    void attack(Enemy& enemy) override;
    void upgrade() override;
    ~GunTower() override;
};