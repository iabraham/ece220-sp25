#include<stdio.h>

int my_first_sum(int *arr){
  int i, sum=0;
  for(i=0; i<5; i++){
    sum += *(arr+ i);
  }

  return sum;
}

int main(void){

  int arr[5]={0};
  int i; 

  for(i=0; i<5; i++){
    printf("Enter a number: \t");
    scanf("%d",&arr[i]);
  }

  printf("\nSum of what you entered is: %d \n", my_first_sum(arr));

  return 0;
  
}
