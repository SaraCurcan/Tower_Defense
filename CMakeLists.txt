cmake_minimum_required(VERSION 4.3)
project(Tower)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tower main.cpp
        Tower.h
        GunTower.h
        Vector2D.h
        ArcherTower.h
        CannonTower.h
        Tower.cpp
        Exceptions.h
        Utils.h
        GunTower.cpp
        ArcherTower.cpp
        CannonTower.cpp
        Enemy.h
        Enemy.cpp
        Zombie.h
        Zombie.cpp
        Skeleton.h
        Skeleton.cpp
)
