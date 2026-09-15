#include <iostream>
#include <cstdlib>
#include <ctime>


int** gener_matrix1(int**& array, int rows, int cols){
    array = new int*[rows];

    for (int i = 0; i < rows; i++){
        array[i] = new int[cols];

        for(int j = 0; j < cols; j++){
            int random = rand() % 10 + 1;
            array[i][j] = random;
        }
    }

    return array;

}

void print_matrix1(int** array, int rows, int cols){
    for(int i = 0; i < rows; i++){

        for(int j = 0; j < cols; j++){
            std::cout << array[i][j] << "\t";
        }

        std::cout << "\n";

    }

}

int main(){
    srand(time(NULL));
    int N = 5;
    int** matrix = nullptr;
    int* D = new int;
    gener_matrix1(matrix, N, N);
    print_matrix1(matrix, N, N);

    for(int i = 0; i < N; i++){
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;

}