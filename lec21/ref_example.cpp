#include <iostream>
using namespace std;

int main(){
  int val = 10;
  int *ptr = &val; // & to get address
  int &ref = val;  // & to declare reference

  cout<<"val  = "<<val<<endl;
  cout<<"*ptr = "<<*ptr<<endl;
  cout<<"ref  = "<<ref<<endl;

  cout<<"--------------"<<endl;

  ref = 20;
  cout<<endl<<"val = "<<val<<endl;
  
  cout<<"--------------"<<endl;

  val = 30;
  cout<<"ref = "<<ref<<endl;

  cout<<"--------------"<<endl;

  cout<<"ptr = "<<ptr<<endl;
  ptr = &ref;
  cout<<"ptr = "<<ptr<<endl;
}
