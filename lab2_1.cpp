#include <iostream>
#include <ctime>

int** genRandMassive(int n){
    int rows = n;
    int cols = n;

    if (n == 0){
        std::cout << "Размер массива должен быть больше 0";
        return nullptr;
    }

    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++){
        arr[i] = new int[cols];
        for(int j = 0; j <= cols; j++){
            arr[i][j] = rand() % 25 + 1;
        }
    }

    return arr;

}

void print(int** arr, int n){
    if(arr == nullptr){
        return;
    }

    int rows = n;
    int cols = n;

    std::cout << "Исходный двумерный массив:\n";
    for (int i = 0; i < rows; i++){

        for(int j = 1; j<cols; j++){
            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }
    
    std::cout << "\n";

};

int main(){
    srand(time(NULL));
    int N = 5;
    int** arr = genRandMassive(N);
    print(arr, N);

    for(int i = 0; i < N; i++){
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}