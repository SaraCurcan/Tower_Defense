#pragma once
#include "Tower.h"
class ArcherTower : public Tower {
private:
    double burnDuration;
public:
    ArcherTower();
    ArcherTower(int rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name,  double bDuration);
    // void attack() override;
    void upgrade() override;
    double getBurnDuration() const;
    void setBurnDuration(double burnDuration);
    ~ArcherTower() override;
};