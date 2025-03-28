#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    char *name;
    unsigned int byear;
    struct person *next;
}node;

// Code to print list - EX 1 (Slide 18)
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


// Code to add at head - EX 1 (Slide 18)
void add_at_head(node **cursor, node *new){
  node* temp=(node*) malloc(sizeof(node));
  temp-> name = new->name;
  temp->byear = new->byear;
  temp->next = new->next;

  if (*cursor == NULL)
    *cursor = temp;
  else{
    temp->next = *cursor;
    *cursor = temp;
  }
}


// Code to add at tail - (Slide 22) 
void add_at_tail(node **cursor, node *new){
  if (*cursor == NULL)
    add_at_head(cursor, new);
  else
    add_at_tail(&(*cursor)->next, new);
}

// Code to delete at head - (Slide 23)
void del_head(node **headptr){
  if (*headptr==NULL)
    return;
  else{
    node *old_head = *headptr;
    *headptr = (*headptr)->next;
    free(old_head);
  }
}

// Code to destroy list - (Slide 23)
void destroy(node **headptr){
  while(*headptr){
    del_head(headptr);
  }
  printf("List destroyed\n");
}

// Code to delete at tail - (Slide 24)
void del_tail(node **cursor){
  if (*cursor==NULL)
    return;
  if ((*cursor)->next==NULL){
    free(*cursor);
    *cursor=NULL;
    return;
  }
  node * second_last = *cursor;
  while (second_last->next->next != NULL)
    second_last=second_last->next;
  free(second_last->next);
  second_last->next = NULL;
}


int main(void){
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  unsigned int byears[] = {1988, 1986, 1990, 1992};
  node temp;
  node * headptr=NULL;

  for (int i=0; i<4; i++){
    temp.name = names[i];
    temp.byear = byears[i];
    temp.next = NULL;
    add_at_tail(&headptr, &temp);
  }

  print_list(headptr);
  printf("\n----------------\n");
  del_head(&headptr);
  print_list(headptr);
  printf("\n----------------\n");
  del_tail(&headptr);
  print_list(headptr);

  destroy(&headptr);

}
