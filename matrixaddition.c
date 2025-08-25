//c program to do simple matrix addition
#include <stdio.h>
#define SIZE 2
void add(int first[SIZE][SIZE], int second[SIZE][SIZE], int result[
SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}
int main() {
    int first[SIZE][SIZE] = { {1, 2}, {3, 4} };
    int second[SIZE][SIZE] = { {5, 6}, {7, 8} };
    int result[SIZE][SIZE];
    add(first, second, result);
    printf("Resultant Matrix:\n");  
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
