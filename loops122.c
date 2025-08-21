#include<stdio.h>
void shabrooza(int arr[],int aux[],int low,int mid,int high){
  int i = low;
  int j = mid + 1;
  int k = low;

while(i<=mid&&j<=high){
  if(arr[i]<=arr[j]){
    aux[k++]=arr[i++];
  }else{
    aux[k++]=arr[j++];
}
}
while(i<=mid){
  aux[k++]=arr[i++];
}
  while(j<=high){
    aux[k++]=arr[j++];
  }
  for(int t=low;t<=high;t++){
    arr[t]=aux[t];
  }
}
void mergesortRec(int arr[],int aux[],int low,int high){
  if(low<high){
    int mid=low+(high-low)/2;
    mergesortRec(arr,aux,low,mid);
    mergesortRec(arr,aux,mid+1,high);
    shabrooza(arr,aux,low,mid,high);
  }
}
void mergesort(int arr[],int n){
  int aux[n];
  mergesortRec(arr,aux,0,n-1);
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {-100, 0, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);

  mergesort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}