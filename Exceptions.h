#pragma once
#include<stdexcept>
#include<string>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& msg) : std::runtime_error(msg) {}
};

class ValueException : public GameException {
public:
    explicit ValueException(const std::string& msg): GameException(msg) {}
};

class NegativeValue: public ValueException {
    double badValue;
public:
    NegativeValue(const std::string& field,double badValue): ValueException("Incorrect value: " + std::to_string(badValue) + " for " + field + ": must be >=0"), badValue(badValue) {}
    double getBadValue() const {return badValue;}
};

class MaxLevelReached : public GameException {
public:
    MaxLevelReached(const std::string& towerName, int maxLevel)
        : GameException(towerName + " is already at max level (" + std::to_string(maxLevel) + ")") {}
};