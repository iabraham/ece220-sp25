#include <iostream>

using namespace std;

class Person{  
  const char *name;  
  unsigned int byear;

public:
  Person *next;  
  Person(const char *name, unsigned int byear);
  Person(const Person &p);
  void print(){
    cout<<"("<<this->name<<", "<<this->byear<<")"<<endl;
  }
};

Person::Person(const char *name, unsigned int byear){
  this->name = name;
  this->byear = byear;
  this->next = NULL;
}

Person::Person(const Person &p){
   this->name = p.name;  
    this->byear = p.byear;
    this->next = NULL;
}

/*** Add my swap code **/ 
template <typename T>
void myswap(T &a, T &b){
  T temp = T(a);  // Call to copy constructor
  a = b; 
  b = temp; 
}

int main(){

  Person p1 = Person("Alex", 1990);
  Person p2 = Person("Mary", 1996);
  myswap(p1, p2);
  cout<<"Alex became: ";
  p1.print();
  cout<<endl;
  cout<<"Mary became: ";
  p2.print();
  cout<<endl;

  return 0;
}
