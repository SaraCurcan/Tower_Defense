#pragma once
#include <iostream>
#include <string>
#include<algorithm>
#include "Vector2D.h"
#include "Enemy.h"
class Enemy;

class Tower {
private:
    double rechargeTime;
    double remainingRecharge;
protected:
    int cost;
    double life;
    double damage;
    int level;
    Vector2D position;
    std::string name;

    bool isRecharged() const;
    void resetCooldown();
    bool canAttack(const Enemy& enemy) const;

public:
    Tower();
    Tower(double rechargeTime, int cost,double life, double damage, int level, Vector2D position, std::string name);
    virtual ~Tower();
    Tower(const Tower& obj) = default;
    Tower& operator=(const Tower& obj) = default;

    double getRechargeTime() const;
    double getRemainingRecharge() const;

    int getCost() const;
    int getLevel() const;

    Vector2D getPosition() const;
    void setPosition( Vector2D newPosition);

    double getLife() const;
    std::string getName() const;

    virtual void upgrade() = 0;
    virtual void attack(Enemy& enemy) = 0;
    bool isDead() const;

    void update(double dt);

    double takeDamage(double amount);
};