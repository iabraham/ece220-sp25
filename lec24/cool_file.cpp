#include <iostream>
#include "bst.hpp"

using namespace std;

/* This file is basically intended to showcase why templating and overloading
 * is actually cool. */

class Person{
  string name; 
  int age; 

public:
  Person(string n, int age){
  name.assign(n);
  this->age = age;
  }

  Person(const Person &p){
    name.assign(p.name);
    age = p.age;
  }

  friend ostream& operator<<(ostream& os, const Person& p){
   os << "(" <<p.name <<", "<<p.age<<")";
   return os;
  }

  bool operator<(const Person& right) const {
  return (age < right.age);
  }

  string get_name() const {
    return name;
  }

  /* QUESTION: Can we make search work for this? */
};

int main(){
  bst <Person> tree1;
  cout<<"Building a Binary Search Tree"<<endl;
  int ages[]= {45, 50, 35, 30, 70, 20, 40, 80, 60};
  string names[]= {"Alex", "Mary", "Sue", "Bob", "Ross", "John", "Joe", "Pete", "Luke"};

  for(int i=0; i<9; i++){
    Person *temp = new Person(names[i], ages[i]);
    tree1.insert(*temp);
  }

  cout<<"Total number of nodes in this tree: ";
  cout<<tree1.node_count()<<endl;
  tree1.inorder();

  cout<<endl;
  tree1.print();
  cout<<"The tree height is: "<<tree1.height();

  vector <Person> v = tree1.vectorize();
  cout<<endl<<"Vectorized in order this is:"<<endl;
  for (auto it= v.begin(); it != v.end(); ++it)
  	  cout<<*it<<", ";

  return 0;
  }

