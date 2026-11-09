#pragma once
#include <string>
#include <vector>
#include <memory>
#include <ostream>
#include "Vector2D.h"

class Enemy;

class Tower {
private:
    double rechargeTime;
    double remainingRecharge;

    Enemy* findTarget(std::vector<std::unique_ptr<Enemy>>& enemies) const;
protected:
    int cost;
    double life;
    double maxLife;
    double damage;
    double range;
    int level;
    Vector2D position;
    std::string name;

    bool isRecharged() const;
    void resetCooldown();
    void setRechargeTime(double newRechargeTime);
    bool isInRange(const Enemy& enemy) const;

    virtual void fire(Enemy& target, std::vector<std::unique_ptr<Enemy>>& enemies) = 0;
    virtual void applyUpgrade() = 0;

public:
    static constexpr int MAX_LEVEL = 5;
    Tower() = delete;
    Tower(double rechargeTime, int cost, double maxLife, double damage, double range,
          Vector2D position, const std::string& name);
    virtual ~Tower()=default;
    Tower(const Tower& obj) = default;
    Tower& operator=(const Tower& obj) = default;

    double getRechargeTime() const;
    double getRemainingRecharge() const;

    int getCost() const;
    int getUpgradeCost() const;
    int getLevel() const;

    Vector2D getPosition() const;
    void setPosition( Vector2D newPosition);

    double getLife() const;
    const std::string& getName() const;
    bool isDead() const;

    double takeDamage(double amount);
    double getMaxLife() const;
    double getRange() const;

    void update(double dt, std::vector<std::unique_ptr<Enemy>>& enemies);
    void upgrade();

    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Tower& tower);

};