#include <stdio.h>

int main(void){
  int num1, num2; 
  printf("Enter the first number:\t");
  scanf("%d", &num1);
  printf("Enter the second number:\t");
  scanf("%x", &num2);
  printf("The sum of %i and %d is: %x\n", num1, num2, num1+num2);
  return 0;
}
