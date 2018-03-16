//
// Created by kamila on 06.03.18.
//

#include "Polybius.h"

char PolybiusArray [5][5] ={{'a','b','c','d','e'},
                            {'f','g','h','i','k'},
                            {'l','m','n','o','p'},
                            {'q','r','s','t','u'},
                            {'v','w','x','y','z'}};

std::string PolybiusCrypt(std::string message){
    message = PrepareString(message);
    std::string crypted;

    for (int i=0; i<message.length(); i++) {
        crypted+= std::to_string(FindInArray(message[i]));
    }

    return crypted;

}

int FindInArray (char element){
    int i=0;
    int j=0;
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            if (PolybiusArray[i][j]==element){
                return (i+1)*10+j+1;
            }
        }
    }
}



std::string PolybiusDecrypt(std::string crypted){
    if (crypted.length()>1){
        std::string message;
        int x,y;
        for (int i=0; i<crypted.length(); i+=2){
            x = crypted[i] - '0'; //covert char to intz
            y = crypted[i+1] - '0';
            message += PolybiusArray[x-1][y-1];
        }
        return message;
    }
    else
        return "";
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

        else if ((message[i]>=97) && (message[i]<=122)){

            if (message[i]==106){//j to i
                message[i]--;
            }
        }
        else{
            //remove white spaces and other
            message.erase(i,1);
            i--;
        }
    }
    return message;
}

