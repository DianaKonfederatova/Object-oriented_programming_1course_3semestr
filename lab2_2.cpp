#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    int rows;
    std::cout << "Введите количество строк:\n";
    std::cin >> rows;

    if (rows <= 0) {
        return 1; 
    }

    int** array = new int*[rows];
    int* sizes = new int[rows];

    for(int i = 0; i < rows; i++){
        std::cout << "Введите количество элементов для строк №" << i+1 << " ";
        std::cin >> sizes[i];

        int n = sizes[i];
        array[i] = new int[n];
        for(int j = 0; j < n; j++){
            array[i][j] = rand() % 100;
        }
        
    }

    std::cout << "Массив:\n";
    for(int a = 0; a < rows; a++){
        for(int b = 0; b < sizes[a]; b++){
            std::cout << array[a][b] << "\t";
        }

        std::cout <<"\n";
    }

    
    for(int j = 0; j<rows; j++){
        delete[] array[j]; 
    }

    delete[] array;
    delete[] sizes;

    return 0;
}