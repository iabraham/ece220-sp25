#include <stdio.h>


void print_array(int *arr, int n, int m){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      printf("%d ", arr[i*n +j]);
    }
    printf("\n");
  }

}



int main(void){

  int arr[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  /* "Name of the array is pointer to first element" 
   * For arr the first element is an array of three ints. 
   * Thus in this case arr has type `int (*)[3]` i.e. a pointer to block of three ints. 
   * Need to explicitly cast to int pointer. 
   */

  print_array((int *) arr , 3, 3);
}
