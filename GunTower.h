#pragma once
#include "Tower.h"

class GunTower : public Tower {
protected:
    void fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>& enemies) override;
    void applyUpgrade() override;
public:
    GunTower();
    GunTower(double rechargeTime, int cost, double maxLife, double damage, double range,
             Vector2D position, const std::string& name);
    GunTower(const GunTower& obj)=default;
    GunTower& operator=(const GunTower& obj)=default;
    ~GunTower() override;
    explicit GunTower(Vector2D position);
};