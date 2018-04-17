//
// Created by kamila on 17.04.18.
//

#include "ArrayFill.h"
#include <iostream>

int main() {
    std::vector<int> vs;
    arrays::FillArray(1024, arrays::UniformFill {77}, &vs);
    return 0;
}

