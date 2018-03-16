//
// Created by kamila on 06.03.18.
//

#include "XorCypherBreaker.h"
std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary)
{



}

std::string Encrypt (std::vector<char> &cryptogram,std::string key){
    std::string encrypted;

    for (int i = 0; i < cryptogram.size(); i++)
        encrypted+= cryptogram[i]^ key[i % (sizeof(key) / sizeof(char))];
}


std::string PrepareString(std::string message){

    for (int i=0; i<message.length(); i++){

        //to lowercase
        if ((message[i]>=65) && (message[i]<=90)){
            if (message[i]==74){ //J to i
                message[i]--;
            }
            message[i]+=32;
        }
        }
    }
    return message;
}