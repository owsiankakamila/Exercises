//
// Created by kamila on 08.03.18.
//

#include <Array2D.h>

int main(){
    int row=5,col=7;
    int ** tab=Array2D(row,col);

    FillArray(tab,row,col);


    DeleteArray2D(tab,row,col);

    return 0;
}