#include <iostream>
#include <ctime>
#include <cstdlib>

int** genRandMatrix(int n, int max){

    if (n == 0){
        n = 1;
    }

    int rows = n;
    int** arr = new int*[rows + 1];

    arr[0] = new int[1];
    arr[0][0] = rows;

    for(int i = 1; i <= rows; i++){
        
        int rand_number_of_elements = rand() % n + 1;
        arr[i] = new int[rand_number_of_elements + 1];
        arr[i][0] = rand_number_of_elements;
        
        for(int j = 1; j<=rand_number_of_elements; j++){
            int rand_numbers = rand() % (max + 1);
            arr[i][j] = rand_numbers;
        }

    }

    return arr;

};

void printMatrix(int** arr){
    if(arr == nullptr){
        return;
    }

    int rows = arr[0][0];
    std::cout << rows << "\n";

    for (int i = 1; i <= rows; i++){
        int number_elements = arr[i][0];
        std::cout << number_elements << ": ";

        for(int j = 1; j<=number_elements; j++){
            std::cout << arr[i][j] << " ";
        }

        std::cout << "\n";
    }
    
    std::cout << "\n";

};

int main(){
    srand(time(NULL));
    int size = rand() % 10;
    if (size == 0) {
        size = 1;
    }
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);

    for(int i = 0; i <= size; i++){
        delete[] matrix[i];
    }

    delete[] matrix;
}