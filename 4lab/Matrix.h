#pragma once
#include <stdexcept>

class Matrix{
    private:
        int** data_;
        int rows_;
        int cols_;
    public:
        Matrix();
        explicit Matrix(int size);
        Matrix(int rows, int cols);
        ~Matrix();
        int get(int i, int j) const;
        void set(int i, int j, int value);
        void inputFromKeyboard();
        void fillRandom();
        void print() const;
        int sum() const;
        int getRows() const;
        int getCols() const;

        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);
};