#include <iostream>
#include <cstdlib>
#include <ctime>

int* genRandArray(int n, int max){
    int *massive = new int[n];
    massive[0] = n;

    for (int i = 1; i<n; i++){
        int randnumbers = rand() % max;
        massive[i] = randnumbers;
    }

};

void print(int* arr){

};


int main(){
    srand(time(NULL));
    int size = rand()%10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    print(arr);
}