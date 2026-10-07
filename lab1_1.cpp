#include <iostream>
#include <cstdlib>
#include <ctime>

int* genRandArray(int n, int max){

    if(n==0){
        std::cout << "В массиве нет элементов\n";
        return nullptr;
    }

    int *massive = new int[n];
    massive[0] = n;

    for (int i = 1; i<n; i++){
        int randnumbers = rand() % max;
        massive[i] = randnumbers;
    }

    return massive;

};

void print(int* arr){
    int size = arr[0];

    std::cout << size << ": ";

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

};

int main(){
    srand(time(NULL));
    int size = rand()%10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);

    if(arr!=nullptr){
        print(arr);
    }
    
    
    delete[] arr;
}