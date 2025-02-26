void Swap(int* one, int* two){
  int temp = *one;
  *one = *two;
  *two = temp;
} 

int partition(int arr[], int start, int end){

  int pivotVal = arr[start];
  int i = start - 1;
  int j = end + 1;

  while(1){
    do i++;
    while (arr[i] < pivotVal);

    do j--;
    while (arr[j] > pivotVal);

    if (i >= j)
      return j;

    Swap(&arr[i], &arr[j]);
  }
}

void QuickSort(int arr[], int start, int end){
  if (start < end){
    int split = partition(arr, start, end);
    QuickSort(arr, start, split);
    QuickSort(arr, split + 1, end);
 }
}
