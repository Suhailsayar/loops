#include<stdio.h>

// Merge two sorted subarrays into a single sorted subarray
void merge(int arr[], int aux[], int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int k = low;

  // Merge the two subarrays
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      aux[k++] = arr[i++];
    } else {
      aux[k++] = arr[j++];
    }
  }

  // Copy remaining elements from the left subarray
  while (i <= mid) {
    aux[k++] = arr[i++];
  }

  // Copy remaining elements from the right subarray
  while (j <= high) {
    aux[k++] = arr[j++];
  }

  // Copy the sorted elements back to the original array
  for (int m = low; m <= high; m++) {
    arr[m] = aux[m];
  }
}

// Recursive merge sort function
void mergesort(int arr[], int aux[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid + 1, high);
    merge(arr, aux, low, mid, high); 
  }
}

// Print the array
void printarray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);  
  }
  printf("\n");
}

int main() {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int aux[n];

  printf("Original array: ");
  printarray(arr, n);

  mergesort(arr, aux, 0, n - 1);

  printf("Sorted array: ");
  printarray(arr, n);

  return 0;
}