#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct person{
    char *name;
    unsigned int byear;
    struct person *next;
}node;

/* Add a node at the head of linked list */ 
void add_at_head(node **cursor, node *new){
  node* temp=(node*) malloc(sizeof(node));
  temp->name=new->name;
  temp->byear=new->byear;
  temp->next=new->next;

  /* If list empty, new item is head */ 
  if (cursor == NULL)
      *cursor = temp;
  else{ /* Else update pointers */ 
    temp->next = *cursor;
    *cursor = temp;
  }
}

/*Add a node at the end of linked list */ 
void add_at_tail(node **cursor, node *new){
  /*If list empty same as adding at head */ 
  if (*cursor == NULL)
    add_at_head(cursor, new);
  else
  /*Else recurse till you find tail */ 
    add_at_tail(&(*cursor)->next, new);
}

/* Delete a node from the head position */ 
void del_head(node **headptr){
  if (*headptr==NULL) /*List empty, do nothing */
    return;
  else{ /*Do bookkeeping to free memory */
    node *old_head = *headptr;
    *headptr = (*headptr)->next;
    free(old_head);
  }
}

/*Delete a given node by name */ 
int delete_node(node **headptr, char *name){
    node *prev;
    node *current = *headptr;

    while (current!=NULL){
     /* Search for element */ 
      if (strcmp(current->name, name)==0)
        break;
      prev = current;
      current = current->next;
    }
    /* Search failed */
    if (current==NULL)
      return -1;

    /* Item was very first item */ 
    if (current == *headptr)
      *headptr = current->next;
    else
    /*Item was somewhere in the middle */
      prev->next=current->next;
    free(current);
    return 0;
}

/* Insert node into linked list preserving sort order */ 
void insert(node **cursor, node *new){
  /* If list empy or first item bigger, insert at head */
  if ((*cursor == NULL) || 
      (*cursor)->byear>=new->byear){
    add_at_head(cursor, new);
    return;
  }
  /* Else recurse to find the right spot to add */
  else{
    insert(&(*cursor)->next, new);
  }
}

void print_list(node *cursor){
  if (cursor==NULL){
    /* List empty; do nothing */ 
    printf("NULL\n");
  }
  else{
    /* Print and recurse */ 
    printf("(%s, %d) -> ", 
           cursor->name, 
           cursor->byear);
    print_list(cursor->next);
  }
}

void destroy(node **headptr){

  // PLEASE IMPLEMENT
}

