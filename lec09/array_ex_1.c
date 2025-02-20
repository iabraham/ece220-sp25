#include<stdio.h>


int main(void){

  int arr[5]={0};
  int i; 

  for(i=0; i<5; i++){
    printf("Enter a number: \t");
    scanf("%d",&arr[i]);
  }

  printf("\n You entered: ");
  for (i=4; i>=0; i--){
    printf("%d ", arr[i]);
  }

  return 0;
  
}
