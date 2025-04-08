#include <iostream>
using namespace std;


class Person{
  const char *name; 
  unsigned int byear; 

public:
  Person *next; 
  Person (const char *name, unsigned int byear){
    this->name = name; 
    this->byear = byear; 
    this->next = NULL;
  }

  void print(){
    cout<<"("<<this->name<< ", "<<this->byear<<")";
  }
};

class LinkedList{
  Person *head; 

  public:
  void add_at_head(Person p){
    Person *new_p = new Person(p); 
    if (head==NULL){
      head = new_p;
    }
    else{
      new_p->next = head; 
      head = new_p; 
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

int main(){

  const char *blue_names[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};

  LinkedList myList; 

  for (int i=0; i<4; i++){
    Person p(blue_names[i], blue_years[i]);
    cout<<"Adding ";
    p.print();
    cout<<endl;
    myList.add_at_head(p);
  }
  cout<<" -------------------------- "<<endl;
  myList.print_list();

}
