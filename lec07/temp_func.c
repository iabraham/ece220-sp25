#include <stdio.h>


float convf2c(int temp_f);



int main(void){
  int temp_f; 
  do {
  printf("Enter temperature in F:\t");
  scanf("%d", &temp_f);
  printf("Value in Celsius is: %f \n", convf2c(temp_f));
  } while (convf2c(temp_f) > -273.15f);
}


float convf2c(int temp_f){
  float retval; 
  retval = (temp_f - 32)*5.0/9.0;
  return retval;
}
