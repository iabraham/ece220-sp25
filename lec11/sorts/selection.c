void selection_sort(int arr[], int n){
  for (int i = 0; i < n - 1; i++){ 
   
    int min_idx = i; // Initialize min to first item

    // Find the minimum in the  sublist: list[i..arraySize-1]
    for (int j = i + 1; j < n; j++)
      if (arr[min_idx] > arr[j])
        min_idx = j;
      
    // swap list[i] with list[currentMinIndex] if necessary;
    if (min_idx != i){
      int min = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = min;
    }
  }
}

