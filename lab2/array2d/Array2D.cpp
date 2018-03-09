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
    int x=1;
    for (int i=0; i<n_columns; i++){
        for (int j=0; j<n_rows; j++){
            array[i][j]=x;
            x++;
        }
    }
}


int **Array2D(int n_rows, int n_columns){
    if ((n_columns <=0 ) || (n_rows<=0)){
        return nullptr;
    }

    int **array = NewArray2D(n_rows, n_columns);

    FillArray(array,n_rows,n_columns);

    return array;


}

int **NewArray2D(int n_rows, int n_columns) {
    int **array =new int*[n_rows];

    for (int i=0;i<n_columns;i++){
        array[i]=new int[n_columns];
    }
    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i=0;i<n_rows;i++){
        delete [] array[i];
    }

    delete [] array;

}