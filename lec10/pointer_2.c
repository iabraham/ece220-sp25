#include <stdio.h>

int main(void){
  int arr[5] = {1, 2, 3, 4, 5};
  int (*arrpw)[5] ;
  int *parr[5]; 

  arrpw = &arr;

  for (int i=0; i<5; i++){
    printf("*(*arrpw + %d): %d\n", i, *(*arrpw + i));
    parr[i] = &arr[i];
  }

  for (int i=2 ; i < 5; i++)
    printf("*parr[%d]: %d\n", i, *parr[i]);
}
