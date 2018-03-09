//
// Created by kamila on 08.03.18.
//

#include "Array2D.h"


void PrintArray(int **array, int n_rows, int n_columns) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            std::cout << std::setw(3)<< array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void FillArray(int **array, int n_rows, int n_columns){
    for (int i=0; i<n_rows; i++){
        for (int j=0; j<n_columns; j++){
            array[i][j]=i+j*n_rows;
        }
    }
}


int **Array2D(int n_rows, int n_columns){
    int **array =new int*[n_columns];

    for (int i=0;i<n_columns;i++){
        array[i]=new int[n_rows];
    }



    return array;


}
void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i=0;i<n_columns;i++){
        delete [] array[i];
    }

    delete [] array;

}