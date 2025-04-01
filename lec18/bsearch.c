#include "linkedlists.c"

node * middle(node *start, node *last){
}


node * binary_search(node *cursor, unsigned int year){
}


node * headptr_prez = NULL;


int main(void){
  char *blues[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};
  
  char *reds[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int red_years[] = {1911, 1946, 1946, 1913};
  
  node temp;
  for (int i=0; i<4; i++){
    temp.name = blues[i];
    temp.byear = blue_years[i];
    temp.next = NULL;
    insert(&headptr_prez, &temp);
  }

  for (int i=0; i<4; i++){
    temp.name = reds[i];
    temp.byear = red_years[i];
    temp.next = NULL;
    insert(&headptr_prez, &temp);
  }

  print_list(headptr_prez);

  node * ww2_baby = binary_search(headptr_prez, 1942);
  printf("President %s was born during WWII", ww2_baby->name);
}

