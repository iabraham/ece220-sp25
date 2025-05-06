#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *left; 
  struct node *right;
  node() : data(0), left(NULL), right(NULL) {};
  node(int d){
    data = d;
    left = NULL;
    right = NULL;
  };
  node(int d, node *l, node *r): data(d), left(l), right(r) {};
};


void tree_print(node *cursor, int depth){
    if (cursor == NULL)
      return;
    for (int i = 0; i < depth; i++)
      printf(i == depth - 1 ? "|-" : "  ");
    printf("%d\n", cursor->data);
    tree_print(cursor->left, depth + 1);
    tree_print(cursor->right, depth + 1);
}


void print_left_boundary(node *nd){
  if (nd==NULL)
    return;
  if (nd->left || nd->right)
    cout << nd->data <<", ";
  node *st = nd->left ? nd->left : nd->right;
  print_left_boundary(st);
 }


void print_leaves(node *cursor){
  if (cursor==NULL)
    return;
  print_leaves(cursor->left);
  if (cursor->left==NULL && cursor->right==NULL)
    cout<<cursor->data<<", ";
  print_leaves(cursor->right);
}

void print_right_boundary(node *nd){
  if (nd==NULL)
    return;
  node *st = nd->right ? nd->right : nd->left;
  print_right_boundary(st);
  if (nd->left || nd->right)
    cout << nd->data <<", ";
}

void print_boundary(node *cursor){

  if (cursor==NULL)
    return;

  cout<<cursor->data<<" ";

	// Print the left boundary
    print_left_boundary(cursor->left);

    // Print all leaf nodes
    print_leaves(cursor->left);
    print_leaves(cursor->right);

    // Print the right boundary 
    print_right_boundary(cursor->right);
}


int main(){
  node *left, *right; 
  left = new node(6);
  right = new node(7, left, NULL);
  left  = new node(4);
  left = new node(5, left, right);
  right = new node(9);
  right = new node(8, left, right);
  left = new node(1);
  left = new node(2, left, NULL);
  node *root = new node(3, left, right);
  tree_print(root, 0);
  print_boundary(root);
}

