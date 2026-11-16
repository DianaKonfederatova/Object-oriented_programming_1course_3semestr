#pragma once

class Matrix{
    private:
        int data_;
        int rows_;
        int cols_;
    public:
        Matrix();
        ~Matrix();
        int get(int i, int j) const;
        void set(int i, int j, int value);
        void inputFromKeyboard();
        void fillRandom();
        void print() const;
        int sum() const;
        int getRows() const;
        int getCols() const;
}