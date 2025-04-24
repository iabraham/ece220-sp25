#include <iostream>
#include <vector>

using namespace std;


template <typename T>
struct treenode{
  T data;
  treenode *left;
  treenode *right;
};

template <class N>
class bst{
private:
  typedef treenode<N> node;
  node *root;

  void insert(N data, node **cursor){
  }

  node *search(N key, node *cursor){
  }
  
  void inorder(node *cursor){
  }

  int countnodes(node *cursor){
  }

  void print(node *cursor, int depth){
    if (cursor == NULL)
      return;
    for (int i = 0; i < depth; i++)
      printf(i == depth - 1 ? "|-" : "  ");
    printf("%d\n", cursor->data);
    print(cursor->left, depth + 1);
    print(cursor->right, depth + 1);
  }

  int height(node *cursor){
  }

  void delete_tree(node *cursor){
  }

  vector<N> vectorize(node *cursor, vector<N> &v){
  }
  
  
public:
  bst(){
    root = NULL;
  }

  void insert(N data){
  }

  treenode<N> *search(N data){
  }

  void inorder(){
  }

  vector<N> vectorize(){
  }

  int node_count(){
  }

  int height(){
  }

  void print(){
    if (root==NULL)
      return;
    else
      print(root, 0);
  }

  ~bst(){
  }
};
