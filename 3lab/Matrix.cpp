#include "Matrix.h"

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0){

}

Matrix::Matrix(int size) : data_(nullptr), rows_(size), cols_(size){
    if(size < 0){
        throw std::invalid_argument("Размерность матрицы не может быть отрицательной");
    }else if(size == 0){
        return;
    }else{
        data_ = new int*[rows_];
        for (int i = 0; i<rows_; i++){
            data_[i] = new int[cols_];
            for (int j = 0; j < cols_; j++){
                if(i == j){
                    data_[i][j] = 1;
                }else{
                    data_[i][j] = 0;
                }
            }
        }
    }
}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols){
    if(rows_ < 0 || cols_ < 0){
        throw std::invalid_argument("Размерность матрицы не может быть отрицательной");
    }else if(rows_ == 0 || cols_ == 0){
        return;
    }else{
        data_ = new int*[rows_];
        for (int i = 0; i<rows_; i++){
            data_[i] = new int[cols_]{};
        }
    }
}

Matrix::~Matrix(){
    if (data_ == nullptr) return;

    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }

    delete[] data_;
}

int Matrix::get(int i, int j) const{
    if(i < 0 || j < 0 || i >=rows_ || j >= cols_){
        throw std::out_of_range("Выход индекса за границы матрицы");
    }

    return data_[i][j];
}
