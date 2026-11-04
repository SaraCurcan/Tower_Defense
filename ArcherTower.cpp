#include "ArcherTower.h"
#include "Utils.h"
#include <iostream>

ArcherTower::ArcherTower():Tower(), burnDuration(0.0){}
ArcherTower::ArcherTower(double rechargeTime, int cost, double life, double damage, int level, Vector2D position, std::string name, double burnDuration):
Tower(rechargeTime,cost,life,damage,level,position,name) {
    Validator::validatePositive("burnDuration", burnDuration);
    this->burnDuration = burnDuration;
}



ArcherTower::~ArcherTower(){}

double ArcherTower::getBurnDuration() const { return burnDuration; }
void ArcherTower::setBurnDuration(double burnDurations) {
    Validator::validatePositive("burnDuration", burnDurations);
    this->burnDuration = burnDurations;
}

void ArcherTower::upgrade() {
    level++;
    damage+=8;
    burnDuration+=0.3;
    std::cout<<"Archer Tower updated to level "<<level<<std::endl;
    std::cout<<"Burn duration : "<<burnDuration<< ". Archer damage: " <<damage <<std::endl;
}

void ArcherTower::attack(Enemy& enemy) {
    enemy.takeDamage(this->damage);
    double burnDamage = this->damage * 0.5 * this->burnDuration;
    enemy.takeDamage(burnDamage);
    std::cout << "ArcherTower applied burn effect for " << burnDuration << " seconds, dealing an extra " << burnDamage << " damage!" << std::endl;
}