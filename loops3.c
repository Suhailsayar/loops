#include<stdio.h>
int main(){
  //code to convert decimal into binary
  int binary[10]={2,2,2,2,2,2,2,2,2,2,};
  int num;
  int i;
  printf("enter the decimal value:");
  scanf("%d",&num);
  while(i<=9)
  {
    binary[i]=num%2;
    num = num/2;
    i++;
  }
  printf("the binary value of the digit is:");
  for(i=9;i>=0;i--){
    printf("%d",binary[i]);
  }
}