#pragma once
#include "Vector2D.h"
#include "Exceptions.h"
#include "Utils.h"

class Tower;

class Enemy {
protected:
    double health;
    double speed;
    int reward;
    double damage;
    Vector2D position;
    double attackTime;
public:
    Enemy();
    Enemy(double health, double speed, int reward, double damage, Vector2D position, double attackTime);

    Enemy(const Enemy& obj) = default;
    Enemy& operator=(const Enemy& obj) = default;
    virtual ~Enemy();

    double getHealth() const;
    double getSpeed() const;
    Vector2D getPosition() const;
    int getReward() const;
    double getDamage() const;
    double getAttackTime() const;

    void setHealth(double health);
    void setPosition(Vector2D position);

    bool isAlive() const;
    void takeDamage(double amount);

    virtual void move(const Vector2D& targetPosition) = 0;
    virtual void attack(Tower& targetTower);
};