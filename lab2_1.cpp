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
        for(int j = 0; j < cols; j++){
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

        for(int j = 0; j<cols; j++){
            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }
    
    std::cout << "\n";

};

void right_diagonal(int** arr, int* D, int n){

    if(arr == nullptr){
        std::cout << "Операция не может быть выполнена, пока массив пуст\n";
        return;
    }

    int rows = n;
    int cols = n;
    int index = 0;

    for(int j_1 = cols-1; j_1 >= 0; j_1--){ 

        int i = 0;
        int j = j_1;

        while(i < n && j >=0){
            D[index] = arr[i][j];
            index++;
            i++;
            j--;
        }
    }

    for(int i_2 = 1; i_2 < rows; i_2++){
        int i = i_2;
        int j = cols - 1;

        while(i < n && j >=0){
            D[index] = arr[i][j];
            index++;
            i++;
            j--;
        }
    }
}

void print_D(int* D, int n){

    for(int i = 0; i < n; i++){
        std::cout << D[i] << " ";
    }

    std::cout << "\n";
}


int main(){
    srand(time(NULL));
    int N = 5;
    int** arr = genRandMassive(N);
    print(arr, N);

    int* D = new int[N*N];
    right_diagonal(arr, D, N);

    std::cout << "Правые диагонали:\n";
    print_D(D, N*N);

    delete[] D;

    for(int i = 0; i < N; i++){
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}