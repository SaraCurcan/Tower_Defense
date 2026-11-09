#pragma once
#include "Tower.h"
class ArcherTower : public Tower {
private:
    double burnDps;
    double burnDuration;
protected:
    void fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>& enemies) override;
    void applyUpgrade() override;
public:
    ArcherTower();
    ArcherTower(double rechargeTime, int cost, double maxLife, double damage, double range,
                Vector2D position, const std::string& name, double burnDps, double burnDuration);
    ArcherTower(const ArcherTower& obj) = default;
    ArcherTower& operator=(const ArcherTower& obj) = default;

    double getBurnDuration() const;
    void setBurnDuration(double burnDuration);
    ~ArcherTower() override;

    double getBurnDps() const;
    explicit ArcherTower(Vector2D position);
    void print(std::ostream& os) const override;
};