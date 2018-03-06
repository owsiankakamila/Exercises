//
// Created by kamila on 04.03.18.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t sum =0;
    int i =1;
    int numb=0;

    numb = CreatePal(i,true);
    while (numb < max_vaule_exculsive){
        if (IsDoubleBasePal(numb))
            sum+=numb;
        i++;
        numb = CreatePal(i,true);
    }

    i=1;

    numb = CreatePal(i,false);
    while (numb < max_vaule_exculsive){
        if (IsDoubleBasePal(numb))
            sum+=numb;
        i++;
        numb = CreatePal(i,false);
    }


    return sum;
}
int CreatePal(int numb, bool even){
    int zero=0;
    int add=0;
    int temp =numb;
    if (even){
        add=temp%10;
        zero++;
    }
    temp=temp/10;
    while(temp){
        add=10*add +temp%10;
        temp = temp/10;
        zero++;
    }


    numb=numb*pow(10,zero)+add; //czy kiedykolwiek nie bedzie rowne 0?
    return numb;
}

bool IsDoubleBasePal (int numb){
    int r,j;
    bool is_pal = true;
    int numb_bin[100];
    int i=0;

    // change to 2- base
    while(numb){
        r=numb%2;
        numb=numb/2;
        numb_bin[i] = r;
        i++;
    }

    i--;

    //check if is palindrome
    for(j=0,i;(i>j) && (is_pal);j++,i--){
        if (numb_bin[i] != numb_bin[j]) {
            is_pal = false;
        }
    }

    return is_pal;

}