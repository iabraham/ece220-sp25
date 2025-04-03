#include<stdio.h>
#include "linkedlists.c"

node * merge_lists(node *list1, node *list2){
  node *result = NULL;
  if (list1==NULL){
    while(list2){
      add_at_tail(&result, list2);
      list2 = list2->next;
      }
    return result; // Rerturn right away beause rest of it will segfault
  }
  if (list2==NULL){
    while(list1){
      add_at_tail(&result, list1);
      list1 = list1->next;
      }
    return result;
  }

  if (list1 && list2){
  if(list1->byear <= list2->byear){
    add_at_tail(&result, list1);
    result->next = merge_lists(list1->next, list2);
  }
  else{
    add_at_tail(&result, list2);
    result->next = merge_lists(list1, list2->next);
  }
  return result;
  }
  else 
  return NULL;
}


void del_list(node **cursor){
  while (*cursor!=NULL)
    del_head(cursor);
}

node * rev_list(node *headptr){
  node *result=NULL;
  while(headptr){
    add_at_head(&result, headptr);
    headptr = headptr->next;
  }
  return result; 
}

node * blue_head = NULL;
node * red_head = NULL;


int main(void){


  // Define the names and birth years of some presidents
  char *blue_names[] = {"Biden", "Carter", "Obama", "Clinton"};
  unsigned int blue_years[] = {1942, 1924, 1961, 1946};
  
  // Define the names and birth years of some presidents
  char *red_names[] = {"Reagan", "Bush", "Trump", "Nixon"};
  unsigned int red_years[] = {1911, 1946, 1946, 1913};

  node temp;

  // Create a linked lists for democrats
  for (int i=0; i<4; i++){
    temp.name = blue_names[i];
    temp.byear = blue_years[i];
    temp.next = NULL;
    insert(&blue_head, &temp);
  }

  // Create a linked list for republicans
  for (int i=0; i<4; i++){
    temp.name = red_names[i];
    temp.byear = red_years[i];
    temp.next = NULL;
    insert(&red_head, &temp);
  }

  print_list(red_head);
  printf("------------------------------------------\n");
  print_list(blue_head);
  printf("------------------------------------------\n");

  node *merged = merge_lists(red_head, blue_head);
  printf("------------------------------------------\n");
  print_list(merged);
  

  printf("------------------------------------------\n");


  print_list(rev_list(merged));

//  // Delete the lists
//  del_list(&merged);
//  printf("Cleared merged\n");
//  
//  del_list(&blue_head);
//  printf("Cleared dems\n");
//
//  del_list(&red_head);
//  printf("Cleared reps\n");
}
