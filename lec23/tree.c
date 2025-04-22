#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;


void add_left(node *cursor, int data){
  if (cursor->left==NULL){
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data; 
    new_node->left = NULL;
    new_node->right = NULL;
    cursor->left = new_node;
  }
  else{
    return;
  }
}

void add_right(node *cursor, int data){
  if (cursor->right==NULL){
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data; 
    new_node->left = NULL;
    new_node->right = NULL;
    cursor->right = new_node;
  }
  else{
    return;
  }
}

void print_preorder(node *cursor){
  if (cursor==NULL){
    return;
  }
  printf("Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data, cursor, cursor->left, cursor->right);
  print_preorder(cursor->left);
  print_preorder(cursor->right);
}

void print_inorder(node *cursor){
  if (cursor==NULL){
    return;
  }
  print_inorder(cursor->left);
  printf("Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data, cursor, cursor->left, cursor->right);
  print_inorder(cursor->right);

}

void print_postorder(node *cursor){
  if (cursor==NULL){
    return;
  }
  print_postorder(cursor->left);
  print_postorder(cursor->right);
  printf("Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data, cursor, cursor->left, cursor->right);
}

void delete_tree(node *cursor){
  if (cursor==NULL){
    return;
  }
  delete_tree(cursor->left);
  delete_tree(cursor->right);
  printf("Deleting Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data, cursor, cursor->left, cursor->right);
  free(cursor);
}

void treeprint(node *cursor, int depth){
  if (cursor == NULL)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  printf("%d\n", cursor->data);
  treeprint(cursor->left, depth + 1);
  treeprint(cursor->right, depth + 1);
}


int main(){
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  node * root = (node *) malloc(sizeof(node));
  root->data = arr[0];
  root->left = NULL;
  root->right=NULL;
  node * cursor = root;

  for (int j=0, i=1; i<11; i=i+2, j++){
    add_left(cursor, arr[i]);
    add_right(cursor, arr[i+1]);
    cursor = (j%2==0) ? cursor->right : cursor->left;
  }
  printf("==================PREORDER=====================\n");
  print_preorder(root);
  printf("===================INORDER===================\n");
  print_inorder(root);
  printf("=================POSTORDER======================\n");
  print_postorder(root);
  printf("==================HUMAN READABLE===============\n");
  treeprint(root, 0);
  delete_tree(root);
}

