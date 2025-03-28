#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person{
    char *name;
    unsigned int byear;
    struct person *next;
}node;

void print_list(node *cursor){
  if (cursor==NULL)
    return;
  else{
    printf("%s was born in %d\n", 
           cursor->name, 
           cursor->byear);
    print_list(cursor->next);
  }
}

void add_at_head(node **cursor, node *new){
  node* temp=(node*) malloc(sizeof(node));
  temp->name=new->name;
  temp->byear=new->byear;
  temp->next=new->next;

  if (cursor == NULL)
      *cursor = temp;
  else{
    temp->next = *cursor;
    *cursor = temp;
  }
}

// Function to insert node (Slide 28)
void insert(node **cursor, node *new){
  if ((*cursor == NULL) || 
      (*cursor)->byear>=new->byear){
    add_at_head(cursor, new);
    return;
  }
  else{
    insert(&(*cursor)->next, new);
  }
}


// Function to delete a node  (Slide 29)
//

node * headptr = NULL;


int main(void){
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  unsigned int years[] = {1988, 1986, 1992, 1990};
  node temp;
  for (int i=0; i<4; i++){
    temp.name = names[i];
    temp.byear = years[i];
    temp.next = NULL;
    insert(&headptr, &temp);
  }
  print_list(headptr);
//  printf("-------------------\n");
//  delete_node(&headptr, "Mary");
//  print_list(headptr);
//
//  printf("-------------------\n");
//  int i=0;
//  while(headptr){
//    if(delete_node(&headptr, names[i])==0)
//      printf("Removed %s\n", names[i]);
//    else
//      printf("Didn't find %s\n", names[i]);
//    i++;
//  }
}


