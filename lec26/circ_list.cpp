#include<iostream>

using namespace std;

typedef struct node{
  int data;
  struct node *next;
  node() : data(-1), next(NULL) {};
  node (int d) : data(d), next(NULL) {};
  node (int d, node *n) : data(d), next(n) {};
}node ;



void print_circlist(node *head){
  if (head==nullptr)
    return;
  node *curr = head; 
  do{ 
    cout<<curr->data<< " ";
    curr = curr ->next; 
  }
  while (curr != head);
  cout <<endl;
}

node* sortedInsert(node* head, int data){  
	// Create the new node with the given data
  node* newNode = new node(data); 
  
  // If linked list is empty
  if (head == nullptr){
    newNode->next = newNode; 
    head = newNode;
    return head; 
  }
  
  node* curr = head;
  node* nextToCurr = head->next;
  
  // Insert at the beginning if data is less 
	// than or equal to head's data
  if (data <= head->data) {
    node* lastNode = head;
    // Find the last node
    while (lastNode->next!=head){
      lastNode = lastNode->next;
    }

    // Set new node's next to head
    newNode->next = head;
    
    // Update last node's next to new node
    lastNode->next = newNode; 

   // Update head to new node
    head = newNode; 
    return head;
  }
  
  // Insert in the middle of the list
  while (curr->next != head) {
    if (curr->data < data && nextToCurr->data >= data) {
     // Set new node's next to current's next
      newNode->next = curr->next; 
      curr->next = newNode; 
      return head; 
    } else { // Move to next set 
      curr = curr->next;
      nextToCurr = nextToCurr->next;
    }
  }
  
  // Insert at the end of the list
  newNode->next = head; 
  curr->next = newNode; 
  return head;
}

int main(){
  node *head = nullptr;
  head = sortedInsert(head, 5);
  head = sortedInsert(head, 6);
  head = sortedInsert(head, 8);
  head = sortedInsert(head, 3);
  head = sortedInsert(head, 7);
  head = sortedInsert(head, 4);

  print_circlist(head);
}

