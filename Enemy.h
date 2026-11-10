#pragma once
#include <vector>
#include <memory>
#include <string>
#include <ostream>
#include "Vector2D.h"

class Tower;
class Path;

class Enemy {
private:
    const Path* path;
    std::size_t nextWaypoint;
    bool reachedEnd;

    void tickTimers(double dt);
    Tower* findTowerInRange(std::vector<std::unique_ptr<Tower>>& towers) const;
protected:
    double health;
    double maxHealth;
    double speed;
    int reward;
    double damage;
    double attackRange;
    Vector2D position;
    double attackTime;
    double remainingAttackTime;

    double burnTimeLeft;
    double burnDps;

    bool canAttack(const Tower& targetTower) const;
    void resetAttackCooldown();
    void heal(double amount);
    virtual bool canAttackTowers() const;

public:
    Enemy();
    Enemy(double maxHealth, double speed, int reward, double damage, Vector2D position,
          double attackTime, double attackRange);

    Enemy(const Enemy& obj) = default;
    Enemy& operator=(const Enemy& obj) = default;
    virtual ~Enemy();

    double getHealth() const;
    double getMaxHealth() const;
    double getSpeed() const;

    Vector2D getPosition() const;
    int getReward() const;
    double getDamage() const;
    double getAttackTime() const;
    double getAttackRange() const;

    void setHealth(double health);
    void setPosition(Vector2D position);
    void setPath(const Path& path);

    bool isAlive() const;
    void takeDamage(double amount);

    void move(double dt);
    virtual void attack(Tower& targetTower);

    void update(double dt, std::vector<std::unique_ptr<Tower>>& towers);
    bool isAttackReady() const;

    void applyBurn(double dps, double duration);
    bool isBurning() const;
    virtual void takeHeavyHit();

    bool hasReachedEnd() const;

    virtual std::string getType() const = 0;
    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);
};