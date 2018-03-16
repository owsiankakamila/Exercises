//
// Created by kamila on 06.03.18.#

#include "GreatestProduct.h"

int main(){
    std::vector <int> a = {-11, -90, -4, -5, -9, -1, -3, 1};

    QuickSort(a,0,a.size()-1);
    for (int v : a) {
        std::cout<<v<<std::endl;
    }
    std:: cout << GreatestProduct(a,2);

    return 0;
}