#include <iostream>
#include "Matrix.h"

int main(){
    Matrix m1;
    Matrix m2(3);
    Matrix m3(3,4);
    Matrix m4(2, 3);
 
    std::cout << "Матрица m2 (3x3 квадратная, единичная):\n";
    m2.print();
    std::cout << "Матрица m3 (3x4 заполнена 0):\n";
    m3.print();
    std::cout << "Матрица m4 (2x3 заполнена 0):\n";
    m4.print();

    for(int i = 0; i < m2.getRows(); i++){
        for(int j = 0; j < m2.getCols(); j++){
            m2.set(i, j, i * j);
        }
    }

    std::cout << "Перезаписанная матрица m2 (3×3):\n";
    m2.print();

    m3.fillRandom();
    std::cout << "Перезаписанная матрица m3 (3x4):\n";
    m3.print();

    m4.inputFromKeyboard();
    std::cout << "Перезаписанная матрица m4 (2x3):\n";
    m4.print();

    std::cout << "Сумма элементов матрицы m3: " << m3.sum() << "\n";

    try {
        Matrix bad(-1, 5); 
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
    
    try {
        m3.get(100, 100); 
    } catch (const std::out_of_range& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
}