#include "linkedlists.c"


void enqueue(node **cursor, node *new){
  add_at_tail(cursor, new);
}


node *dequeue(node **headptr){
  if (*headptr==NULL){
    return NULL;
  }
  else{
    node *dqueued = (node *) malloc(sizeof(node));
    dqueued->name = (*headptr)->name;
    dqueued->byear = (*headptr)->byear;
    dqueued->next = NULL;
    del_head(headptr);
    return dqueued;
  }
}

node *front = NULL;


int main(void){
  unsigned int years[] = {1988, 1986, 1990, 1992};
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  node temp;

  for (int i=0; i<4; i++){
    temp.name = names[i];
    temp.byear = years[i];
    temp.next = NULL;
    enqueue(&front, &temp);
  }

  print_list(front);
  printf("--------------\n");
  node * removed = dequeue(&front);
  printf("We removed %s\n", removed->name);
  printf("--------------\n");
  print_list(front);

  // Call destroy to prevent memory leaks
}
