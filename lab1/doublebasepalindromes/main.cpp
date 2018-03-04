//
// Created by kamila on 04.03.18.
//

#include <iostream>
#include <cstdint>
#include <vector>

uint64_t DoubleBasePalindromes(int max_vaule_exculsive);
int CreatePal(int numb, bool even);
bool IsDoubleBasePal (int numb);


int main() {
    if (IsDoubleBasePal(0)) std::cout << "TAK!" << std::endl;

    return 0;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t sum =0;
    int i =1;
    bool flag =true;
    int numb=0;

    while(flag &&(numb<=max_vaule_exculsive)){
        flag = false;




    }
}
int CreatePal(int numb, bool even){
    int zero=0;
    int add=0;
    int temp =numb;
    if (even){
        add=temp%10;
        temp=temp/10;
        zero++;
    }
    while(temp){
        add=10*add +temp%10;
        temp = temp/10;
        zero++;
    }
    if (zero!=0) numb=numb*(10*zero)+add; //czy kiedykolwiek nie bedzie rowne 0?
    return numb;
}

bool IsDoubleBasePal (int numb){
    int r,j;
    bool is_pal = true;
    std::vector < int > numb_bin;

    while(numb){

        r=numb%2;
        numb=numb/2;
        numb_bin.push_back(r);
    }

    int i=numb_bin.size();
    for(i,j=0;i<j,is_pal;i--,j++){
        if (numb_bin[i] != numb_bin[j]) {
            is_pal = false;
        }
    }


    return is_pal;

}