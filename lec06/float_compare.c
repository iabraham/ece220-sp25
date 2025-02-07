#include<stdio.h>

int main(void){
  float my_float = 3.14; 

  if (my_float == 3.14f)
    printf("My float is PI\n");
  else
    printf("My float is not PI\n");

  double my_double = 3.14;
  if (my_double == 3.14)
    printf("My double is PI\n");
  else
    printf("My double is not PI\n");

  printf("%lu, %lu, %lu\n", sizeof(3.14), sizeof(3.14f), sizeof(my_float));
  return 0;
}
