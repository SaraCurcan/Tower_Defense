#include <iostream>
#include "Vector2D.h"
#include "ArcherTower.h"
#include "Zombie.h"
#include "Skeleton.h"

int main() {
    ArcherTower myTower(2, 100, 100.0, 15.0, 1, Vector2D(100.0, 100.0), "Archer", 1.5);

    Zombie zombie(80.0, 2.0, 5, 25.0, Vector2D(0.0, 0.0), 1.0, 80.0);
    Skeleton skeleton(50.0, 2.5, 3, 10.0, Vector2D(10.0, 10.0), 0.8);

    std::cout << "Initial Zombie position: (" << zombie.getPosition().x << ", " << zombie.getPosition().y << ")" << std::endl;
    zombie.move(myTower.getPosition());
    std::cout << "Zombie position after move: (" << zombie.getPosition().x << ", " << zombie.getPosition().y << ")" << std::endl;

    std::cout << "Zombie health before lifesteal attack: " << zombie.getHealth() << std::endl;
    zombie.attack(myTower);
    std::cout << "Zombie health after lifesteal attack: " << zombie.getHealth() << std::endl;

    std::cout << "Is zombie alive? " << (zombie.isAlive() ? "YES" : "NO") << std::endl;
    std::cout << "Is skeleton alive? " << (skeleton.isAlive() ? "YES" : "NO") << std::endl;

    return 0;
}