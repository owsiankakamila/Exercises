//
// Created by kamila on 06.03.18.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <iostream>
#include <string>
#include <vector>
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);

std::string Encrypt (std::vector<char> &cryptogram,std::string key);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
