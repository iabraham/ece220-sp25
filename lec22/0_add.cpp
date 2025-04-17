#include <iostream>
using namespace std;

template <typename T>
T Add(T a, T b){
  return a+b;
}

template <typename T1, typename T2>
T2 Add(T1 a, T2 b){
  return a+b;
}

int main(){
  cout<<Add(1, 3)<<endl; // Integers
  cout<<Add(1.2, 3.5)<<endl; // Doubles 
  cout<<Add(1.2, 3.5f)<<endl; // Doubles 
//   cout<<Add(2, 'C')<<endl;
}
