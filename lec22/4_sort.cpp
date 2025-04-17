#include <algorithm> 
#include <iostream> 

using namespace std; 

template <typename T>
void show(T a[], int array_size){
  int i=0;
  for (i = 0; i < array_size-1; ++i) 
    cout << a[i] << ", ";
  cout<<a[i]<<endl;
} 

int main(){ 
//    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
    char a[] = {'E', 'C', 'E', '2', '2', '0'};

    int asize = sizeof(a) / sizeof(a[0]); 
    cout << "The array before sorting is: \n"; 
    show(a, asize); 

    sort(a, a + asize); 
    cout << "\n\nThe array after sorting is:\n"; 
    show(a, asize); 
    return 0; 
}



