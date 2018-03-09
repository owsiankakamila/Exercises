//
// Created by kamila on 04.03.18.
//

#include "Palindrome.h"

bool IsPalindrome(std::string str){
    int i=0;
    int j=str.size()-1;
    for (i,j ;j>i;i++,j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}