#include <stdio.h>
#include <math.h>

/* Given array, normalize by maximum element */
void max_norm(float *arr, int n){
  float max = arr[0];
  for (int i = 1; i < n; i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }
  for (int i = 0; i < n; i++){
    arr[i] /= max;
  }
}

/* Given array, normalize to be unit vector */
void unit_norm(float *arr, int n){
  float sum = 0;
  for (int i = 0; i < n; i++){
    sum += arr[i] * arr[i];
  }
  float norm = sqrt(sum);
  for (int i = 0; i < n; i++){
    arr[i] /= norm;
  }
}

// Expensive function takes array, size and pointer to function as arguments. 
void expensive(float *arr, int n, void (*norm_func)(float *, int)){
  printf("I am expensive function, I do lots of compute, and my body is 10K lines of code\n");
  printf("BUT my input arr could have many normalizations and different people like to use different ones!\n");
  printf("Sometimes they write their own custom routines!\n\n");
  printf("For example you called me with some function living at: %p\n", norm_func);
  norm_func(arr, n);
}

int main(void){
  float arr1[] = {1, 2, 3, 4, 5};
  float arr2[] = {1, 2, 3, 4, 5};

  expensive(arr1, 5, &max_norm);
  printf("\nHi arr1 here. Now I am max normalized: ");
  for(int i=0; i<5; i++)
    printf("%f, ", arr1[i]);

  printf("\n\n");
  
  expensive(arr2, 5, &unit_norm);
  printf("\nHi arr2 here. Now I am unit normalized: ");
  for(int i=0; i<5; i++)
    printf("%f, ", arr2[i]);
  
}
