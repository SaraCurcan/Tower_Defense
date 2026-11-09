#include <iostream>
#include <vector>
#include <memory>
#include "GunTower.h"
#include "ArcherTower.h"
#include "CannonTower.h"
#include "Zombie.h"
#include "Skeleton.h"
#include "Exceptions.h"

using namespace std;

using EnemyList = vector<unique_ptr<Enemy>>;

void printEnemies(const EnemyList& enemies) {
    for (size_t i = 0; i < enemies.size(); i++) {
        cout << "  enemy " << i << ": hp " << enemies[i]->getHealth()
             << (enemies[i]->isBurning() ? " (burning)" : "")
             << (enemies[i]->isAlive() ? "" : " (dead)") << "\n";
    }
}


void testConstructors() {
    cout << "\n##### TEST 1: constructors + operator<< #####\n";
    GunTower defaultGun;
    GunTower quickGun(Vector2D{1, 1});
    ArcherTower fullArcher(2.0, 120, 100.0, 8.0, 5.0, Vector2D{2, 2}, "MyArcher", 4.0, 2.0);
    CannonTower cannon(Vector2D{3, 3});
    CannonTower copyCannon(cannon);       // copy constructor

    cout << defaultGun << "\n" << quickGun << "\n" << fullArcher << "\n"
         << cannon << "\n" << copyCannon << "\n";
}

void testUpgrade() {
    cout << "\n##### TEST 2: upgrade + MaxLevelReached #####\n";
    ArcherTower archer(Vector2D{0, 0});
    cout << archer << "\n";
    try {
        for (int i = 0; i < 6; i++) {
            archer.upgrade();
            cout << "after upgrade: " << archer << "\n";
        }
    } catch (const MaxLevelReached& e) {
        cout << "CAUGHT: " << e.what() << "\n";
    }
}


void testGun() {
    cout << "\n##### TEST 3: GunTower (cooldown + range) #####\n";
    GunTower gun(Vector2D{0, 0});
    EnemyList enemies;
    enemies.push_back(make_unique<Skeleton>(100.0, 2.0, 5, 10.0, Vector2D{10, 0}, 1.0)); // in afara razei (3)

    for (int step = 1; step <= 6; step++) {
        if (step == 3) {
            enemies[0]->setPosition(Vector2D{2, 0});   // intra in raza
            cout << "-- skeleton enters range --\n";
        }
        enemies[0]->update(0.5);
        gun.update(0.5, enemies);
        cout << "t=" << step * 0.5 << "s  hp " << enemies[0]->getHealth()
             << "  reload " << gun.getRemainingRecharge() << "\n";
    }
}


void testArcher() {
    cout << "\n##### TEST 4: ArcherTower (burn 3s) #####\n";
    ArcherTower archer(Vector2D{0, 0});
    EnemyList enemies;
    enemies.push_back(make_unique<Zombie>(100.0, 1.0, 10, 20.0, Vector2D{2, 0}, 1.0, 100.0));

    for (int step = 1; step <= 10; step++) {
        enemies[0]->update(0.5);
        archer.update(0.5, enemies);
        cout << "t=" << step * 0.5 << "s  hp " << enemies[0]->getHealth()
             << (enemies[0]->isBurning() ? "  (burning)" : "") << "\n";
    }
}


void testCannon() {
    cout << "\n##### TEST 5: CannonTower (area damage) #####\n";
    CannonTower cannon(Vector2D{0, 0});          // range 3.5, area 1.5
    EnemyList enemies;
    enemies.push_back(make_unique<Skeleton>(80.0, 2.0, 5, 10.0, Vector2D{3, 0}, 1.0));       // tinta (cel mai apropiat din raza)
    enemies.push_back(make_unique<Skeleton>(80.0, 2.0, 5, 10.0, Vector2D{3.5f, 0.5f}, 1.0)); // in zona de impact
    enemies.push_back(make_unique<Zombie>(100.0, 1.0, 10, 20.0, Vector2D{3, 1}, 1.0, 100.0)); // in zona de impact
    enemies.push_back(make_unique<Skeleton>(80.0, 2.0, 5, 10.0, Vector2D{3, 4}, 1.0));       // prea departe de impact

    cout << "before:\n"; printEnemies(enemies);
    cannon.update(0.1, enemies);
    cout << "after 1st shot:\n"; printEnemies(enemies);
    cout << "cannon reload: " << cannon.getRemainingRecharge() << "s\n";
}


void testTowerDamage() {
    cout << "\n##### TEST 6: enemy attacks tower #####\n";
    GunTower tower(Vector2D{0, 0});
    Zombie zombie(100.0, 1.0, 10, 60.0, Vector2D{1, 0}, 1.0, 150.0);
    for (int step = 1; step <= 6 && !tower.isDead(); step++) {
        zombie.update(1.0);
        zombie.attack(tower);
        cout << "t=" << step << "s  tower life " << tower.getLife()
             << "  zombie hp " << zombie.getHealth() << "\n";
    }
    cout << (tower.isDead() ? "tower destroyed\n" : "tower survived\n");
}

void testValidation() {
    cout << "\n##### TEST 7: validation #####\n";
    try {
        GunTower bad(0.0, 100, 200.0, 20.0, 3.0, Vector2D{0, 0}, "Bad");   // rechargeTime = 0
    } catch (const GameException& e) {
        cout << "CAUGHT: " << e.what() << "\n";
    }
    try {
        GunTower g(Vector2D{0, 0});
        g.takeDamage(-5);
    } catch (const GameException& e) {
        cout << "CAUGHT: " << e.what() << "\n";
    }
}

int main() {
    try {
        testConstructors();
        testUpgrade();
        testGun();
        testArcher();
        testCannon();
        testTowerDamage();
        testValidation();
    } catch (const GameException& e) {
        cerr << "UNEXPECTED ERROR: " << e.what() << endl;
        return 1;
    }
    return 0;
}