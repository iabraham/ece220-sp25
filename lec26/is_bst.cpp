#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
  node() : data(0), left(NULL), right(NULL){};
  node(int d) : data(d), left(NULL), right(NULL){};
  node(int d, node *l, node *r) : data(d), left(l), right(r){};
};

void tree_print(node *cursor, int depth) {
  if (cursor == NULL)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  printf("%d\n", cursor->data);
  tree_print(cursor->left, depth + 1);
  tree_print(cursor->right, depth + 1);
}

bool is_bst(node *cursor, node *&prev){
// FILL IN CODE
}

int main() {

  node *right = new node(13);
  node *left = new node(7, NULL, right);
  right = new node(12, left, NULL);
  right = new node(10, NULL, right);
  left = new node(5, new node(3), new node(6));
  node *root = new node(8, left, right);

  tree_print(root, 0);

  node *prev = NULL;

  if (is_bst(root, prev))
    cout << "Tree is BST";
  else
    cout << "Tree is not BST";
}

