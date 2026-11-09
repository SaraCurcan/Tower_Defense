#pragma once
#include <string>
#include "Exceptions.h"

class Validator {
public:
    static void validatePositive(const std::string& field, double value) {
        if (value<0)
            throw NegativeValue(field,value);
    }
    static void validateStrictPositive(const std::string& field,double value) {
        if (value<=0)
            throw NegativeValue(field,value);
    }
};