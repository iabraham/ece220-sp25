#include<stdio.h>

/* This function is a recursive implementation of binary search algorithm. It
 * returns a pointer to the key/search element in the array. 
 * If the key element is not found, it returns a null pointer. 
 *
 * Compared to the standard version, this one only takes the array, array size
 * and search key as input. The standard version also requires to keep passing
 * in left and right pointers. 
 */

int * binary_opt2(int arr[], int n, int key){
  int mid;
  // Check array has at more than one element 
  if (n > 1) {
    // We will be passing real sub arrays along with their sizes at each step
    // so mid is always n/2
    mid = n/2; 

    if (key==arr[mid])
      // return pointer to the key element
      return &arr[mid];
    else if (key > arr[mid]) 
      // Search right half
      // Sub array starts from mid+1 and size is n-mid
      return binary_opt2(&arr[mid+1],n-mid, key);
    else 
      // Search left half 
      // Sub array starts from same point but size is mid
      return binary_opt2(arr, mid, key);
  }
  // If array has only one element
  else if (arr[0]==key)
      return arr;
  else
    return NULL;
}

int main() {
  int arr[] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23};
  int size = sizeof(arr) / sizeof(arr[0]);
  int index, key = 12;

  int *result = binary_opt2(arr, size, key);
  if (result == NULL)
    printf("Element not found");
  else{
    // Find index based on pointer arithmetic
    index = (result-arr); 
    printf("Element found at index: %d", index);
  }
}
