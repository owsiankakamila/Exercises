//
// Created by owsikami on 06.06.18.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H

#include <iostream>
#include <string>
 std::string ArabicToRoman (int i){
     if(i>3999){
         throw std::invalid_argument("To high number");
     }
     return std::to_string(i);
 }



#endif //JIMP_EXERCISES_ARABICROMAN_H
