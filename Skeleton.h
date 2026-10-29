#pragma once
#include "Enemy.h"

class Skeleton : public Enemy {
public:
    Skeleton();
    Skeleton(double health, double speed, int reward, double damage, Vector2D position, double attackTime);

    Skeleton(const Skeleton& obj) = default;
    Skeleton& operator=(const Skeleton& obj) = default;
    ~Skeleton() override;

    void move(const Vector2D& targetPosition) override;
};