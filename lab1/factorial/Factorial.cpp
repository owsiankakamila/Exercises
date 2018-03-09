//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int Factorial(int value) {
    if ((value >= 13) || (value <= -13)) return 0;
    else if (value == 0) return 1;
    else if (value > 0) {
        return value * Factorial(value - 1);
    } else {
        return value * Factorial(value + 1);
    }

}

int factorialIT(int value) {
    int result = 1;
    if ((value >= 13) || (value <= -13)) return 0;
    else if (value == 0) return 1;
    else if (value > 0) {
        for (int i = value; i > 0; i--) {
            result = result * i;
        }
    } else {
        for (int i = value; i < 0; i++) {
            result = result * i;
        }
    }
    return result;

}

