#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    char *name;
    unsigned int byear;
    struct person *next;
}node;

// Code to print list - EX 1 (Slide 18)



// Code to add at head - EX 1 (Slide 18)


// Code to add at tail - (Slide 22) 


// Code to delete at head - (Slide 23)

// Code to destroy list - (Slide 23)


// Code to delete at tail - (Slide 24)
//

int main(void){
  char *names[] = {"Alex", "John", "Mary", "Sue"};
  unsigned int byears[] = {1988, 1986, 1990, 1992};
  node temp;
  node * headptr=NULL;

  for (int i=0; i<4; i++){
    temp.name = names[i];
    temp.byear = byears[i];
    temp.next = NULL;
    add_at_head(&headptr, &temp);
  }

  print_list(headptr);


}
