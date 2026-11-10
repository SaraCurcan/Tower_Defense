#pragma once
#include "Enemy.h"

class Zombie : public Enemy {
private:
    static constexpr double heal_percent = 0.20;
public:
    Zombie();
    Zombie(double maxHealth, double speed, int reward, double damage, Vector2D position,
          double attackTime, double attackRange);
    explicit Zombie(Vector2D position);

    Zombie(const Zombie& obj) = default;
    Zombie& operator=(const Zombie& obj) = default;
    ~Zombie() override;

    void attack(Tower& targetTower) override;
    std::string getType() const override;
};