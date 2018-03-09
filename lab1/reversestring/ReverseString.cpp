//
// Created by kamila on 04.03.18.
//

#include "ReverseString.h"


std::string Reverse(std::string str){
    if (str[0]=='\0') return str;
    return Reverse(&str[1])+str[0];
}