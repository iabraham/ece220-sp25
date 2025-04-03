#include "linkedlists.c"


node * pop(node **stacktop){
  if (*stacktop==NULL){
    return NULL;
  }
  else{
    node *popped = (node *) malloc(sizeof(node));
    popped->name = (*stacktop)->name;
    popped->byear = (*stacktop)->byear;
    popped->next = NULL;
    del_head(stacktop);
    return popped;
  }
}

void push(node **cursor, node *new){
  add_at_head(cursor, new);
}


node * stacktop = NULL;

int main(void){
  unsigned int years[] = {1988, 1986, 1990, 1992};
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  node temp;

  for (int i=0; i<4; i++){
    temp.name = names[i];
    temp.byear = years[i];
    temp.next = NULL;
    push(&stacktop, &temp);
  }

  print_list(stacktop);
  printf("--------------\n");
  node * popped = pop(&stacktop);
  printf("We popped %s\n", popped->name);
  printf("--------------\n");
  print_list(stacktop);

  // Call destroy to prevent memory leaks

}
