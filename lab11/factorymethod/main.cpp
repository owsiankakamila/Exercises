//
// Created by owsikami on 23.05.18.
//

#include "FactoryMethod.h"
#include <iostream>
#include <bits/unique_ptr.h>
using namespace factoryMethod;
using namespace std;

int main (){
    int *p = new int (33);
    int d= Value(p);
    cout<< d << endl;

    unique_ptr <double> ptr = make_unique<double>(1.7);
    double dd = Value(ptr);
    cout << dd;

    return 0;
}

