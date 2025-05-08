#include "linkedList.h"


int DetectLoop(node *head){
  node *slow = head; 
  node *fast = head; 
  while (slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next; 
    if (slow == fast){
      return 1;
    }
  }
  return 0; 
}

node *CopyList(node *head){
  if (head==NULL){
    return NULL;
  }
  node *newHead = malloc(sizeof(node));

  newHead->value = head->value; 
  newHead->next = CopyList(head->next);

  node *current = head; 
  node *currentNew = newHead; 

  while (current){
    currentNew->arbit = current->arbit; 
    current = current->next;
    currentNew = currentNew->next;
  }
   
  return newHead;
}
