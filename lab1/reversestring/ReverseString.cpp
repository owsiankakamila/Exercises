//
// Created by kamila on 04.03.18.
//

#include "ReverseString.h"


std::string reverse(std::string str){
    if (str[0]=='\0') return str;
    return reverse(&str[1])+str[0];
}