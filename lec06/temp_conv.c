#include <stdio.h>

float f2c(int temp_f){
  return (temp_f - 32)*5.0/9.0;
}


int main(void){
  int temp_f; 
  float temp_c;
  do {
  printf("Enter temperature in F:\t");
  scanf("%d", &temp_f);
  temp_c = f2c(temp_f);
  printf("Value in Celsius is: %f", temp_c);
  } while (temp_c > -273.15f);
}
