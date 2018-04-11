//
// Created by kamila on 10.04.18.
//

#include <utility>

#include <complex>
#include <complex.h>
#include "Matrix.h"

algebra::Matrix::Matrix(int cols, int rows) {
    cols_ = cols;
    rows_ = rows;
}

algebra::Matrix::Matrix() {
    cols_ = 0;
    rows_ = 0;

}

algebra::Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements): mat_{elements} {
    // size of elements = cols_
    cols_=mat_.size();
    // size of elements[i] = rows_
    rows_=elements.size();

}

std::pair<size_t, size_t > algebra::Matrix::Size() const {
    return {rows_,cols_};
}

