#include "linkedlists.c"

node * middle(node *start, node *last){

  // List is empty 
  if (start==NULL)
    return NULL;

  node *slow = start; 
  node *fast = start->next; 

  while (fast != last){
    fast = fast->next;
    if (fast != last){
      slow = slow ->next;
      fast = fast->next;
    }
  }

  return slow;
}


node * binary_search(node *cursor, unsigned int year){
  /* This function calls middle */ 
  node *start, *end; 
  start = cursor; 
  end = NULL;

  do{
  node *mid = middle(start, end);
  if (mid==NULL){

    // Kept going right or list is empty
    return NULL;
  }
  if (mid->byear == year)
    return mid; 
  else if (mid->byear < year){
    // Need to go right 
    start = mid->next; 
  }
  else{
    // Need to go left 
    end = mid; 
  }
  }while(end==NULL || end!=start);

  return NULL;
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

