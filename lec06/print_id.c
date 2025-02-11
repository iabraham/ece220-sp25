#include <stdio.h>


int main(void){
  int n; 
  int i, j;
  printf("Enter a positive integer: \t");
  scanf("%d", &n);

  if (n>=1 && n<=8){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if (i==j){
          printf("1 ");
        }
        else if(i>j){
          printf("0 ");
        }
      }
      printf("\n");
    }
  }
  else {
  printf("Enter a number between 1-8 please. Exiting...");
  }
}
