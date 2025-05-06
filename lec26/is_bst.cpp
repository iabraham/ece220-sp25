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

void tree_print(node *cursor, int depth, char c) {
  if (cursor == NULL)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  printf("%c: %d\n", c, cursor->data);
  tree_print(cursor->left, depth + 1,  'L');
  tree_print(cursor->right, depth + 1, 'R');
}

bool is_bst(node *cursor, node *&prev){
  if (cursor==NULL)
    return true;

  bool left = is_bst(cursor->left, prev);

  if (prev!=NULL && cursor->data <= prev->data)
    return false;

  prev = cursor;
  bool right = is_bst(cursor->right, prev);

  return (left && right);

}
int main() {
  node *left, *right;
  left = new node(7);
  right = new node(8, left, NULL);
  left = new node(3);
  left = new node(5, left, right);
  right = new node(25);
  right = new node(20, new node(18), right);
  node *root = new node(10, left, right);

  tree_print(root, 0, 'O');

  node *prev = NULL;

  if (is_bst(root, prev))
    cout << "Tree is BST";
  else
    cout << "Tree is not BST";
}

