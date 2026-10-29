#pragma once
#include "Enemy.h"

class Zombie : public Enemy {
private:
    double maxHealth;
    void checkLife();
public:
    Zombie();
    Zombie(double health, double speed, int reward, double damage, Vector2D position, double attackTime, double maxHealth);

    Zombie(const Zombie& obj) = default;
    Zombie& operator=(const Zombie& obj) = default;
    ~Zombie() override;

    void move(const Vector2D& targetPosition) override;
    void attack(Tower& targetTower) override;
};