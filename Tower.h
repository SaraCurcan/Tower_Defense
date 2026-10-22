#pragma once
#include <iostream>
#include <string>
#include "Vector2D.h"
class Tower {
private:
    int rechargeTime;
protected:
    int cost;
    double life;
    double damage;
    int level;
    Vector2D position;
    std::string name;
public:
    Tower();
    Tower(int rechargeTime, int cost,double life, double damage, int level, Vector2D position, std::string name);
    virtual ~Tower();
    int getRechargeTime() const;

    int getCost() const;
    // void setCost(int newCost);
    int getLevel() const;

    Vector2D getPosition() const;
    void setPosition( Vector2D newPosition);

    double getLife() const;
    std::string getName() const;

    virtual void upgrade() = 0;
    // virtual void attack(Enemy& enemy) = 0;
    bool isDead() const;

    void update(double dt);
    bool isRecharged() const;
};