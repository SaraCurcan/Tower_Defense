#pragma once
#include "Exceptions.h"
#include <string>
using namespace std;
class Validator {
public:
    static void validatePositive(const string& field, double value) {
        if (value<0)
            throw NegativeValue(field,value);
    }
    static void validateStrictPositive(const string& field,double value) {
        if (value<=0)
            throw NegativeValue(field,value);
    }
};