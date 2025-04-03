#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct dll_node{
  char *name; 
  struct dll_node *next;
  struct dll_node *prev;
}dll_node;


void print_forward(dll_node *cursor){
  printf("HEAD -> ");
  while(cursor){
    printf("%s -> ", cursor->name);
    cursor  = cursor->next;
  }
  printf("NULL\n");
}

void delete_by_name(dll_node **cursor, char *key){
 // Left as an exercise 
}

void print_reverse(dll_node *cursor){
  dll_node *tmp = cursor; 
  while(tmp->next)
    tmp=tmp->next; 
  printf("TAIL ->");
  while(tmp){
    printf("%s -> ", tmp->name);
    tmp=tmp->prev;
  }
  printf("HEAD\n");
}

void dll_insert(dll_node **head, char *v){
  dll_node *new_node = malloc(sizeof(dll_node));
  new_node->name = v; 
  new_node->next = new_node->prev = NULL;

  // List is empty or v is smallest value 
  if (*head ==NULL || strcmp((*head)->name, v)>0){
    new_node->next = *head;
    if(*head)
      (*head)->prev = new_node;
    *head = new_node; 
    return;
  }

  // Find the right place to insert new node 
  dll_node *cursor = *head;
  while(cursor->next && strcmp(cursor->next->name, v)<0)
    cursor = cursor->next;

  //Insert the node 
  new_node->next = cursor->next;

  // if not adding at the tail position need to rewire succeeding elements pointers
  if(cursor->next)
    cursor->next->prev = new_node; 

  cursor->next = new_node; 
  new_node->prev = cursor; 

}


int main(void){
  dll_node *head = NULL;

  dll_insert(&head, "Ivan");
  dll_insert(&head, "Alex");
  dll_insert(&head, "Molly");
  dll_insert(&head, "David");
  dll_insert(&head, "John");
  dll_insert(&head, "Zoe");

  print_forward(head);
  printf("===============================\n");
  print_reverse(head);

  return 0; 
}
