#include <iostream>
using namespace std;

/*Same class definition from before for Person; 
 * we only add a copy constructor AND A FRIEND FUNCTION!
 */
class Person{
  const char *name; 
  unsigned int byear; 

public:
  Person *next; 

  // Standard constructor
  Person (const char *name, unsigned int byear){
    this->name = name; 
    this->byear = byear; 
    this->next = NULL;
  }

  // Copy constructor
  Person(const Person &p){
    this->name = p.name;  
    this->byear = p.byear;
    this->next = NULL;
  }

//  void print(){
//    cout<<"("<<this->name<< ", "<<this->byear<<")";
//  }
//

  // NEW FUNCTION!!!
  friend ostream& operator<<(ostream& os, const Person& p){
  os << "(" <<p.name <<", "<<p.byear<<")";
  return os;
  }

  // CHANGED!!
  void print(){
    cout<<(*this);
  }
};

/* Same definition of LinkedList we have always had.
 * No really -- check! */
class LinkedList{
  public:
  Person *head; 
  void add_at_head(Person &p){
    Person *new_p = new Person(p); 
    if (head==NULL){
      head = new_p;
    }
    else{
      new_p->next = head; 
      head = new_p; 
    }
  }

  void add_at_tail(Person &p){
    if (head==NULL)
      add_at_head(p);
    else{
      Person *cursor = head; 
      while (cursor->next)
        cursor = cursor->next;
      cursor->next = new Person(p);
    }
  }

  void del_at_head(){
    if (head==NULL)
      return; 
    else{
      Person *temp = head; 
      head = head->next; 
      delete temp; 
    }
  }

  LinkedList(){
    head = NULL;
  }

  ~LinkedList(){
    while (head)
      del_at_head();
  }

  void print_list(){
    Person *cursor = head; 
    while(cursor){
      cursor->print();
      cout<<" -> ";
      cursor = cursor->next;
    }
    cout << "NULL\n";
  }
};

/* This is now beauty of inheritance. Stack based on LinkedList should not
 * expose the LinkedList's head, or add_at_head and del_at_head functions.
 *
 * The protected mode does EXACTLY that. 
 */

class Stack:protected LinkedList{
  public:
  void push(Person &p){
    // NOW WE CAN DO THIS! 
    cout<<"Pushing: " <<p<<endl;
    add_at_head(p);
  }

  Person * pop(){
    Person *p = new Person(*head); // Copy constructor!
    del_at_head();
    return p;
  }

  /* Protected derivation means now that the print_list function of the
  * superclass is not exposed. No worries, we write our own! */
  void print_list(){
    cout<<"TOS -> ";

    // Syntax to call super class's print_list function. 
    LinkedList::print_list();
  }
};


int main(){

  const char *blue_names[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};

  Stack myStack;
  for (int i=0; i<4; i++){
    Person p(blue_names[i], blue_years[i]);
    myStack.push(p);
  }
  cout<<"\n-------------STACK-----------------"<<endl;
  myStack.print_list();

  cout<<"\n"<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl<<"\n";
  
  LinkedList myList;
  for (int i=0; i<4; i++){
    Person p(blue_names[i], blue_years[i]);
    cout<<"Adding via add_at_tail: ";
    p.print();
    cout<<endl;
    myList.add_at_tail(p);
  }
  cout<<"\n-----------LINKED LIST------------ "<<endl;
  myList.print_list();

}
