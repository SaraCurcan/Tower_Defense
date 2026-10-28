#pragma once
#include "Tower.h"
#include "CannonTower.h"
class CannonTower : public Tower {
private:
    double damageArea;
public:
    CannonTower();
    CannonTower(int rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name, double damageArea);
    CannonTower(const CannonTower& obj) = default;
    CannonTower& operator=(const CannonTower& obj) = default;
    
    // void attack() override;
    void upgrade() override;
    double getDamageArea() const;
    void setDamageArea(double damageArea);
    ~CannonTower() override;

};