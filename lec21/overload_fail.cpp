#include <iostream>

using std::cout;
using std::endl;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// void swap(int a, int b){
//     int temp = a;
//     a = b;
//     b = temp;
// }


int main(){
  int val1, val2;
  val1 = 10, val2 = 20;

  cout<<"val1 = "<<val1<<endl;
  cout<<"val2 = "<<val2<<endl;

//  swap(&val1, &val2);
//  cout<<endl<<"val1 = "<<val1<<endl;
//  cout<<"val2 = "<<val2<<endl;

  swap(val1, val2);
  cout<<endl<<"val1 = "<<val1<<endl;
  cout<<"val2 = "<<val2<<endl;
}
