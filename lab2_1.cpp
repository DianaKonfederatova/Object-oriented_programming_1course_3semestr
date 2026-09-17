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

void right_diagonal(int* D, int** matrix, int rows, int cols, int& index){
    int count_el = cols;

    for(int i = 0; i < rows; i++){
            D[index] = matrix[i][cols - 1 - i];
            index++;
    }
  
}



int main(){
    srand(time(NULL));
    int N = 5;
    int** matrix = nullptr;
    int size_D = N * N;
    int* D = new int[size_D];
    int cur_index = 0;
    gener_matrix1(matrix, N, N);
    std::cout << "Матрица:\n";
    print_matrix1(matrix, N, N);

    for(int i = 0; i < N; i++){
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] D;

    return 0;

}