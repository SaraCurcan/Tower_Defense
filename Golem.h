#pragma once
#include "Enemy.h"

class Golem : public Enemy {
private:
    static constexpr double hit_percent = 0.25;
protected:
    bool canAttackTowers() const override;
public:
    Golem();
    Golem(double maxHealth, double speed, int reward, double damage, Vector2D position);
    explicit Golem(Vector2D position);

    Golem(const Golem& obj) = default;
    Golem& operator=(const Golem& obj) = default;
    ~Golem() override;

    void takeHeavyHit() override;
    std::string getType() const override;
};