#include "linkedlists.c"


node * pop(node **stacktop){
}

void push(node **cursor, node *new){
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

}
