// c program to implement binary search on a sorted array
#include <stdio.h>
int binary_search(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;  
        if (arr[mid] == x) {
            return mid; // Return the index if the element is found
        }
        if (arr[mid] < x) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if the element is not found
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binary_search(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in array\n");
    }
    return 0;
}