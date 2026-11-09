#pragma once
#include "Tower.h"
#include "CannonTower.h"
class CannonTower : public Tower {
private:
    double damageArea;
protected:
    void fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>& enemies) override;
    void applyUpgrade() override;
public:
    CannonTower();
    CannonTower(double rechargeTime, int cost, double maxLife, double damage, double range,
                Vector2D position, const std::string& name, double damageArea);
    explicit CannonTower(Vector2D position);
    CannonTower(const CannonTower& obj) = default;
    CannonTower& operator=(const CannonTower& obj) = default;

    double getDamageArea() const;
    void setDamageArea(double damageArea);
    ~CannonTower() override;
    void print(std::ostream& os) const override;

};