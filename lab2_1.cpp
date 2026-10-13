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

void print_D(int* D, int n){

    for(int i = 0; i < n; i++){
        std::cout << D[i] << " ";
    }

    std::cout << "\n";
}


void left_diag(int** arr, int* D, int n) {
    int index = 0;
    
    for (int start_col = n - 1; start_col >= 0; --start_col) {
        int i = 0;           
        int j = start_col;   
        
        while (i < n && j < n) {
            D[index++] = arr[i][j];
            i++;
            j++;
        }
    }
    
    
    for (int start_row = 1; start_row < n; ++start_row) {
        int i = start_row;   
        int j = 0;           
        
        while (i < n && j < n) {
            D[index++] = arr[i][j];
            i++;
            j++;
        }
    }
}

void right_diag(int** arr, int* D, int n) {
    int index = 0;
    
    for (int start_col = 0; start_col < n; ++start_col) {
        int i = 0;           
        int j = start_col;  
        
        while (i < n && j >= 0) {
            D[index++] = arr[i][j];
            i++;
            j--;
        }
    }
    
    for (int start_row = 1; start_row < n; ++start_row) {
        int i = start_row;   
        int j = n - 1;       
        
        while (i < n && j >= 0) {
            D[index++] = arr[i][j];
            i++;
            j--;
        }
    }
}

void spiral_top_left(int** arr, int* D, int n) {
    int index = 0;
    
    int top = 0;        
    int bottom = n - 1; 
    int left = 0;       
    int right = n - 1;  
    
    while (top <= bottom && left <= right) {
        
        for (int col = left; col <= right; ++col) {
            D[index++] = arr[top][col];
        }
        top++; 

        for (int row = top; row <= bottom; ++row) {
            D[index++] = arr[row][right];
        }
        right--; 

        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                D[index++] = arr[bottom][col];
            }
            bottom--;
        }
        
        
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                D[index++] = arr[row][left];
            }
            left++;
        }
    }
}

void spiral_center(int** arr, int* D, int n) {
    int index = 0;
    
    int row = n / 2;
    int col = n / 2;
    
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    
    int direction = 0;   
    int step_length = 1; 
    int total = n * n;   
    
    while (index < total) {
        
        for (int half_turn = 0; half_turn < 2; ++half_turn) {
            
            for (int step = 0; step < step_length && index < total; ++step) {
                
                if (row >= 0 && row < n && col >= 0 && col < n) {
                    D[index++] = arr[row][col];
                }
                
                row += dr[direction];
                col += dc[direction];
            }
            
            direction = (direction + 1) % 4;
        }
        
        step_length++;
    }
}

int main(){
    srand(time(NULL));
    int N = 5;
    int** arr = genRandMassive(N);
    print(arr, N);

    int* D = new int[N*N];
    left_diag(arr, D, N);

    std::cout << "Левые диагонали:\n";
    left_diag(arr, D, N);
    print_D(D, N * N);

    std::cout << "Правые диагонали:\n";
    right_diag(arr, D, N);
    print_D(D, N * N);

    std::cout << "Спираль, начиная с центра:\n";
    spiral_center(arr, D, N);
    print_D(D, N * N);

    std::cout << "Спираль, начиная с левого верхнего элемента:\n";
    spiral_top_left(arr, D, N);
    print_D(D, N * N);

    delete[] D;
    for(int i = 0; i < N; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}