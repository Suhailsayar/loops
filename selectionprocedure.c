#include<stdio.h>
 static int partition(int arr[],int low,int high){
  int pivot = arr[high];
  int i = low-1;
  for(int j = low;j<high;j++){
    if(arr[j]<pivot){
      i++;
      int temp = arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
  }
  int temp = arr[i+1];
  arr[i+1]=arr[high];
  arr[high]=temp;
  return i+1;
}
 int selection_procedure(int arr[],int low,int high,int k){
    while(low<=high){
      int p = partition(arr,low,high);
      if( p == k ) return arr[p];
      else if(p<k)
      {
        selection_procedure(arr,p+1,high,k);
      }else{
        selection_procedure(arr,p-1,high,k);
      }
    }
    return -1;
}
int main(){
  int arr[]={88,106,108,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = 1;
  int val = selection_procedure(arr,0,n-1,k-1);
printf(" %d smallest: %d\n",k,val);
return 0;
}