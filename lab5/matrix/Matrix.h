//
// Created by kamila on 10.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <vector>

namespace algebra {
    class Matrix {
    public:
        // param constructor
        Matrix (int cols, int rows);
        // default constructor
        Matrix ();
        //Matlab constructor
        Matrix (const std::string &str);
        //initializer list constructor
        Matrix (const std::initializer_list<std::vector<std::complex<double>>> &elements);



        //copy constructor
        Matrix(const Matrix &matrix);
        //copy assignment??
        Matrix &operator=(const Matrix &matrix);

        //get size
        std::pair<size_t , size_t > Size()const;
        // print
        std::string Print() const;
        //pop elemnet
        std::complex<double> Pop(int cols, int rows)const;


        //set element // bool?
        void Set(int cols, int rows, std::complex<double> val);

        // +
        Matrix Add(const Matrix &mat2)const;//?
        // -
        Matrix Sub(const Matrix &mat2);
        // *
        Matrix Mul(Matrix mat2);
        Matrix Mul(int x);
        // :
        Matrix Div( Matrix mat2);
        Matrix Div(int x);
        // ^
        Matrix Pow(int x);



    private:
        std::vector<std::vector<std::complex<double>>> mat_; //size row


        int rows_;
        int cols_;

    };
}



#endif //JIMP_EXERCISES_MATRIX_H
