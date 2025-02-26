void insertionSort(int list[], int arraySize){
   for (int i = 1; i < arraySize; i++){
     /** insert list[i] into a sorted sublist list[0..i-1] so that
         list[0..i] is sorted. */
     int currentElement = list[i];
     int k;

     for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
       list[k + 1] = list[k];

     // Insert the current element into list[k+1]
     list[k + 1] = currentElement;
   }
 }

