#include <iostream>
using namespace std;

class Animal{
public:
  virtual void eat(){
    cout << "I'm eating generic food." << endl;
  }
};

class Cat : public Animal{
public:
  void eat(){
    cout << "I'm eating a mouse." << endl;
  }
};

void eat_lunch(Animal *a){
  a->eat();
}

int main(){
  Animal *anim = new Animal();
  Cat *bruno = new Cat();

  // Take care of breakfast 
  anim->eat();
  bruno->eat();

  // Take care of lunch
  eat_lunch(anim);
  eat_lunch(bruno);
}

