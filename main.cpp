#include <iostream>
#include "GunTower.h"
#include "Zombie.h"

using namespace std;

int main() {
    try {
        GunTower tower(3.0, 100, 200.0, 30.0, 1, Vector2D(0, 0), "GunTower");
        Zombie zombie(100.0, 1.5, 10, 20.0, Vector2D(2, 2), 2.0, 150.0);

        double dt = 1.0;

        cout << "=== INITIAL STATE ===" << endl;
        cout << "Tower life: " << tower.getLife() << endl;
        cout << "Zombie health: " << zombie.getHealth() << endl;

        for (int i = 1; i <= 10; i++) {
            cout << "\n=== SECOND " << i << " ===" << endl;

            tower.update(dt);
            zombie.update(dt);

            tower.attack(zombie);
            zombie.attack(tower);

            cout << "Tower life: " << tower.getLife() << endl;
            cout << "Zombie health: " << zombie.getHealth() << endl;

            cout << "Tower cooldown: " << tower.getRemainingRecharge() << endl;
            cout << "Zombie cooldown ready: " << zombie.isAttackReady() << endl;

            if (tower.isDead() || !zombie.isAlive()) {
                cout << "\nGAME OVER!" << endl;
                break;
            }
        }
    }
    catch (const ValueException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}