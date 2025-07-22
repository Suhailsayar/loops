#include<stdio.h>
int main(){
  int count=0;
  int i = 0;
  int j = 0;
  int k = 0;
  for(i = 0; i < 10; i++)
  for(j = 0; j < 10; j++)
    for(k=0; k < 10; k++){
    printf("hello world\n");
      count++;
}
// the time complexity of this code is O(n^3) where n is 10
// this loop is exactly printing the statement 1000 times that is satisfying its time complexity

  printf("Total count: %d\n", count);
}