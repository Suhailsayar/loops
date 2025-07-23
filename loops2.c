#include<stdio.h>
int main(){
  int count=0;
  int i = 1;
  int j = 1;
  int k = 1;
  int n=10;
  for(i = 1; i <=n ; i++)
  for(j = 1; j <= i ; j++)
    for(k=1; k <= n*n*n; k++){
    printf("hello world\n");
      count++;
    }
  printf("%d\n",count);
}
  