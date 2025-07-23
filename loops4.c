#include<stdio.h>
int main(){
  //code to convert binary into decimal
  int binary[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int num;
  int i = 0;
  printf("enter the binary value (10 bits): ");
  for(i = 0; i < 10; i++) {
    scanf("%d", &binary[i]);
  }
  int decimal = 0;
  for(i = 0; i < 10; i++) {
    decimal += binary[i] * (1 << (9 - i));
  }
  printf("the decimal value of the binary digit is: %d\n", decimal);
  return 0;
}