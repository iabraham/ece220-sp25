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
  // FILL IN CODE
}

node* sortedInsert(node* head, int data) {
  
  	// Create the new node with the given data
    node* newNode = new node(data); 
    
    // If linked list is empty
    if (head == nullptr) {
    }
    
    node* curr = head;
    node* nextToCurr = head->next;
    
    // Insert at the beginning if data is less 
  	// than or equal to head's data
    if (data <= head->data) {
        node* lastNode = head;
       	// Find the last node
      
      	// Set new node's next to head
        
      	// Update last node's next to new node
        
      	// Update head to new node
    
        return head;
    }
    
    // Insert in the middle of the list
    while (curr->next != head) {
        if (curr->data < data && nextToCurr->data >= data) {
          	
          	// Set new node's next to current's next
        } else {
          
          	// Move to the next node
        }
    }
    
    // Insert at the end of the list
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

