#include <iostream>

using namespace std;

class Animal{
  const char *name; 
public:
  virtual void eat()=0;
  Animal(char *n){
    name = n; 
  }
};

class Cat : public Animal{
public:
//  void eat(){
//    cout << "I'm eating a mouse." << endl;
//  }
  Cat(char *n): Animal(n){
  }
};



int main(){
//  Animal *a = new Animal("Giraffe");
  Cat *c = new Cat("Tom");
}

