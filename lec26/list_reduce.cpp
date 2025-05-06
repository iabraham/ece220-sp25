#include <iostream>
using namespace std;

typedef struct node{
  int data;
  struct node *next;
  node() : data(-1), next(NULL) {};
  node (int d) : data(d), next(NULL) {};
  node (int d, node *n) : data(d), next(n) {};
}node ;

void print_list(node *cursor){
  while(cursor){
    cout<< cursor->data << ", ";
    cursor = cursor->next;
  }
  cout<<endl;
}

node * reduce_list(node *cursor){
  node *new_list = NULL;
  while (cursor){
    if (cursor->data%2==1)
      new_list = new node(cursor->data, new_list);
    cursor=cursor->next;
  }
  return new_list;
}

int main(){
  node *temp = NULL;
  int vect[] = {9, 8, 7, 5, 2, 3, 5, 2 };
  for (int i=0; i<8; i++)
	  temp = new node(vect[i], temp); 
  node *full_list = new node(1, temp);

  print_list(full_list);

  node *red_list = reduce_list(full_list);
  // Reversed
  print_list(red_list);
  
  //Not reversed
  print_list(reduce_list(red_list));
}

