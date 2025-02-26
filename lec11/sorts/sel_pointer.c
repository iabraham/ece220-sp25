# include<stdio.h>
/* Advanced Material:
 * If you want to test your pointer skills. */ 

/* Function finds the index of the minimum valued element
* in an array of n integers */

int find_min(int arr[], int n){
  int i, idx=0;
  for (i=1; i<n; i++){
    if (arr[i] < arr[idx])
      idx = i;
  }
  return idx; 
}

/* Swaps the values of two integers */ 
void swap(int *one, int *two){
  int temp = *one; 
  *one = *two; 
  *two = temp; 
}

/* Performs selection sort by utilizing the swap & find_min 
  * functions. */
void sel_sort(int arr[], int n){
  int pos, min_idx;
  for (pos=0; pos<n; pos++){
    // Find index of minimum element in subarray arr[pos:end]
    min_idx = pos +  find_min(&arr[pos], n-pos);
    // Swap it with the element in the arr[pos] location 
    swap(&arr[pos], &arr[min_idx]);
  }
}


int main(void){
  int arr[] = {17, 43, 9, 40, 11, 68, 13};
  int i;
  
  for (i=0; i<7; i++)
    printf("%d ", arr[i]);

  printf("\n");
  sel_sort(arr, 7);
  
  for (i=0; i<7; i++)
    printf("%d ", arr[i]);
}

