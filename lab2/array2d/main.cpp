//
// Created by kamila on 08.03.18.
//

#include <Array2D.h>

int main(){
    int row=1,col=3;
    int ** tab=Array2D(row,col);

    PrintArray(tab,row,col);


    DeleteArray2D(tab,row,col);

    return 0;
}