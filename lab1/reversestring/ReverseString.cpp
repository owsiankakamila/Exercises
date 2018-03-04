//
// Created by owsikami on 02.03.18.
//

#include "ReverseString.h"

std::string reverse(std::string str){
    if (str[0] == '\0') return;
    else reverse(&str[1]) + str[0];
}