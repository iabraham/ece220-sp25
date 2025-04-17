#include <iostream>

// You need to make "node.h" from 2_template_ll.cpp
#include "node.h"

using namespace std;

class Person{  
  const char *name;  
  unsigned int byear;

public:
  Person *next;  
  Person(const char *name, unsigned int byear);
  Person(const Person &p);
  void print(){
    cout<<(*this);
  }
  friend ostream& operator<<(ostream& os, const Person& p);
};

Person::Person(const char *name, unsigned int byear){  
  this->name = name;
  this->byear = byear;
}

Person::Person(const Person &p){
  this->name = p.name;
  this->byear = p.byear;
}

ostream& operator<<(ostream& os, const Person& p){
  os << "(" <<p.name <<", "<<p.byear<<")";
  return os;
}

int main(){

  const char *names_dems[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int years_dems[] = {1942, 1924, 1961, 1946};

  const char *names_reps[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int years_reps[] = {1911, 1946, 1946, 1913};

  LinkedList<Person> PrezList;

  for (int i=0; i<4; i++){
    Person p= Person(names_dems[i], years_dems[i]);
    PrezList.add_at_head(p);
  }
  PrezList.print_list();
  printf("\n------------------------\n");


  for (int i=0; i<4; i++){
    Person p= Person(names_reps[i], years_reps[i]);
    PrezList.add_at_head(p);
  }
  PrezList.print_list();

}
