//c program to implement strassen's matrix multiplication
#include <stdio.h>
#include <stdlib.h>
void add(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void subtract(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void strassen(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return; 
    }
    int newSize = size / 2;
    int **A11 = (int **)malloc(newSize * sizeof(int *));
    int **A12 = (int **)malloc(newSize * sizeof(int *));
    int **A21 = (int **)malloc(newSize * sizeof(int *));
    int **A22 = (int **)malloc(newSize * sizeof(int *));
    int **B11 = (int **)malloc(newSize * sizeof(int *));
    int **B12 = (int **)malloc(newSize * sizeof(int *));
    int **B21 = (int **)malloc(newSize * sizeof(int *));
    int **B22 = (int **)malloc(newSize * sizeof(int *));
    int **C11 = (int **)malloc(newSize * sizeof(int *));
    int **C12 = (int **)malloc(newSize * sizeof(int *));
    int **C21 = (int **)malloc(newSize * sizeof(int *));
    int **C22 = (int **)malloc(newSize * sizeof(int *));
    int **M1 = (int **)malloc(newSize * sizeof(int *));
    int **M2 = (int **)malloc(newSize * sizeof(int *));
    int **M3 = (int **)malloc(newSize * sizeof(int *));
    int **M4 = (int **)malloc(newSize * sizeof(int *));
    int **M5 = (int **)malloc(newSize * sizeof(int *));
    int **M6 = (int **)malloc(newSize * sizeof(int *));
    int **M7 = (int **)malloc(newSize * sizeof(int *));
    int **AResult = (int **)malloc(newSize * sizeof(int *));
    int **BResult = (int **)malloc(newSize * sizeof(int *));
    for (int i = 0; i < newSize; i++) {
        A11[i] = (int *)malloc(newSize * sizeof(int));
        A12[i] = (int *)malloc(newSize * sizeof(int));
        A21[i] = (int *)malloc(newSize * sizeof(int));
        A22[i] = (int *)malloc(newSize * sizeof(int));
        B11[i] = (int *)malloc(newSize * sizeof(int));
        B12[i] = (int *)malloc(newSize * sizeof(int));
        B21[i] = (int *)malloc(newSize * sizeof(int));
        B22[i] = (int *)malloc(newSize * sizeof(int));
        C11[i] = (int *)malloc(newSize * sizeof(int));
        C12[i] = (int *)malloc(newSize * sizeof(int));
        C21[i] = (int *)malloc(newSize * sizeof(int));
        C22[i] = (int *)malloc(newSize * sizeof(int));
        M1[i] = (int *)malloc(newSize * sizeof(int));
        M2[i] = (int *)malloc(newSize * sizeof(int));
        M3[i] = (int *)malloc(newSize * sizeof(int));
        M4[i] = (int *)malloc(newSize * sizeof(int));
        M5[i] = (int *)malloc(newSize * sizeof(int));
        M6[i] = (int *)malloc(newSize * sizeof(int));
        M7[i] = (int *)malloc(newSize * sizeof(int));
        AResult[i] = (int *)malloc(newSize * sizeof(int));
        BResult[i] = (int *)malloc(newSize * sizeof(int));
    }
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    add(A11, A22, AResult, newSize);
    add(B11, B22, BResult, newSize);
    strassen(AResult, BResult, M1, newSize);
    add(A21, A22, AResult, newSize);
    strassen(AResult, B11, M2, newSize);
    subtract(B12, B22, BResult, newSize);
    strassen(A11, BResult, M3, newSize);
    subtract(B21, B11, BResult, newSize);
    strassen(A22, BResult, M4, newSize);
    add(A11, A12, AResult, newSize);
    strassen(AResult, B22, M5, newSize);
    subtract(A21, A11, AResult, newSize);
    add(B11, B12, BResult, newSize);
    strassen(AResult, BResult, M6, newSize);
    subtract(A12, A22, AResult, newSize);
    add(B21, B22, BResult, newSize);
    strassen(AResult, BResult, M7, newSize);
    add(M1, M4, AResult, newSize);
    subtract(AResult, M5, BResult, newSize);
    add(BResult, M7, C11, newSize);
    add(M3, M5, C12, newSize);
    add(M2, M4, C21, newSize);
    add(M1, M3, AResult, newSize);
    subtract(AResult, M2, BResult, newSize);
    add(BResult, M6, C22, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    for (int i = 0; i < newSize; i++) {
        free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
        free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
        free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);
        free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]);
        free(M5[i]); free(M6[i]); free(M7[i]);
        free(AResult[i]); free(BResult[i]);
    }
    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(C11); free(C12); free(C21); free(C22);
    free(M1); free(M2); free(M3); free(M4);
    free(M5); free(M6); free(M7);
    free(AResult); free(BResult); 
}
int main() {
    int size = 4;
    int **A = (int **)malloc(size * sizeof(int *));
    int **B = (int **)malloc(size * sizeof(int *));
    int **C = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
    }
    int count = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {  
            A[i][j] = count;
            B[i][j] = count;
            count++;
        }
    }
    strassen(A, B, C, size);
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}