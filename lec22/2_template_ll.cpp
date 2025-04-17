#include <iostream>

using namespace std;

template <typename T>
class Node{
  T data; 
public:
  Node<T> * next; 
  Node(T inval){
      data = inval; 
      next = NULL;
  }
  void print(){ cout<<data; }
};

template <class H>
class LinkedList{
H *head;  

public:  
  LinkedList(){  
    this->head = NULL;  
  }
  void print_list();
  void add_at_head(H &p);
  void del_at_head();
  ~LinkedList();
};

template <typename H>
void LinkedList<H>::print_list(){
  while(head->next){
    head->print();
    cout<<"-->";
    head = head->next;
  }
  head->print();
  cout<<"--> NULL\n";
}

template <typename H>
void LinkedList<H>:: add_at_head(H &p){
  H *temp = new H(p);
  if (head==NULL){
    head = temp;
  }
  else{
    temp->next=head; 
    head = temp;
  }
}

template <typename H>
void LinkedList<H>:: del_at_head(){
  if (head==NULL)
    return;
  else{
    H *temp=head;
    head = head->next;
    delete temp;
  }
}

template <typename H>
LinkedList<H>::~LinkedList(){
  while(head)
    del_at_head();
}


int main(){
  LinkedList<Node <int>> intList;
  for (int i=0; i<5; i++){
    Node<int> temp = Node<int>(i);
    intList.add_at_head(temp);
  }

  intList.print_list();


LinkedList<Node <char>> charList;
  char myarr[] = "022 ECE";

  for (int i=0; i<7; i++){
    Node<char> temp = Node<char>(myarr[i]);
    charList.add_at_head(temp);
  }

  cout<<endl;
  charList.print_list();
}

