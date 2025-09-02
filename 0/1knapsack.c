// program to solve the 0/1 Knapsack problem using dynamic programming
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    return K[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }
    
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);
    
    int maxValue = knapsack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);
    
    return 0;
}