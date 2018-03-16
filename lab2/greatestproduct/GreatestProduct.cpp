//
// Created by kamila on 06.03.18.
//

#include "GreatestProduct.h"

int GreatestProduct2(const std::vector<int> &numbers, int k){
    std::vector <int> helptab;
    int i=0,j;
    int product=1;
    int smallest,pos_smallest;
    bool found = false;


    //fill helptab
    for (i=0; i<k; i++){
        helptab.push_back(numbers[i]);
    }

    for (j=k;j<numbers.size();j++){
        pos_smallest = 0;
        found = false;
        for (i=0; i<k; i++){
            //looking for smallest number in helptab, which is smaller than numbers[j]
            if (helptab[i]<numbers[j]){
                if (helptab[pos_smallest]>=helptab[i]){
                    pos_smallest=i;
                    found =true;
                }
            }
        }
        if (found){
            helptab[pos_smallest] = numbers[j];

        }

    }

    for (i=0; i<k; i++){
        product*=helptab[i];
    }

    return product;

}


int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector <int> helptab;
    std::vector <int> k_tab;
    int max_product=1;
    int product=1;
    int i;

    for (auto v : numbers) {
        helptab.push_back(v);
    }

    QuickSort(helptab,0,helptab.size()-1);


    for(i=helptab.size()-1;k_tab.size()<k;i--){ //i>=helptab.size()-k
        k_tab.push_back(helptab[i]);
        max_product*=helptab[i];
    }


    i=0;
    int j=k-1;

    while ((helptab[i]<0)&&(helptab[i+1]<0)&&(i<helptab.size()-1)&&(j>0)) {
        k_tab[j] = helptab[i];
        k_tab[j - 1] = helptab[i + 1];
        i += 2;
        j -= 2;

        for (auto s : k_tab) {
            product *= s;

        }
        if (product > max_product) {
            max_product = product;
            product = 1;
        }

        for (auto s : k_tab) {
            std::cout<<s<<std::endl;
        }


    }

    for (auto s : k_tab) {
        std::cout<<s<<std::endl;
    }



    return max_product;
    }



void QuickSort(std::vector<int> &tab,int p, int r){

    if (p<r){
        int q = Partition(tab,p,r);
        QuickSort(tab,p,q);
        QuickSort(tab,q+1,r);
    }
}

int Partition(std::vector<int> &tab,int p, int r){
    int x = tab[p];
    int i = p-1;
    int j = r+1;
    int temp;

    while(true){
        do {
            j--;
        }while(tab[j]>x);

        do {
            i++;
        }while(tab[i]<x);

        if (i<j){
            temp =tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
        }
        else{
            return j;
        }
    }
}



//oblicz z k najw
//wez 2 najmniejsze i spr czy oba ujemne
// podmien z 2
//spr czy wieksze
//podmieniej dalej az nie bedzie juz par ujemnych