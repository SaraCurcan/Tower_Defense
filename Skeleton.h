#pragma once
#include "Enemy.h"

class Skeleton : public Enemy {
public:
    Skeleton();
    Skeleton(double maxHealth, double speed, int reward, double damage, Vector2D position, double attackTime,double attackRange);

    Skeleton(const Skeleton& obj) = default;
    Skeleton& operator=(const Skeleton& obj) = default;
    ~Skeleton() override;

    explicit Skeleton(Vector2D position);
    std::string getType() const override;
};