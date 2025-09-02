// program to solve fractional knapsack problem using greedy method
#include <stdio.h>

struct Item {
    int value, weight;
    double cost;
};

// Function to compare two items based on cost
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    if (item1->cost < item2->cost) return 1;
    else if (item1->cost > item2->cost) return -1;
    else return 0;
}

// Function to get maximum value in knapsack
double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].cost * W;
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].cost = (double)arr[i].value / arr[i].weight;
    }
    
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);
    
    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %.2lf\n", maxValue);
    
    return 0;
}