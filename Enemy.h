#pragma once
#include "Vector2D.h"

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
    virtual ~Enemy();

    double getHealth() const;
    void setHealth(double health);

    double getSpeed() const;
    void setSpeed(double speed);

    Vector2D getPosition() const;
    void setPosition(Vector2D position);

    bool isAlive() const;
    void takeDamage(double amount);

    virtual void move(const Vector2D& targetPosition) = 0;
    virtual void attack(Tower& targetTower);

    int getReward() const;
    void setReward(int reward);

    double getDamage() const;
    void setDamage(double damage);

    double getAttackTime() const;
    void setAttackTime(double attackTime);


};