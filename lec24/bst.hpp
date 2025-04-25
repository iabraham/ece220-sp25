#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct treenode{
  T data;
  treenode *left;
  treenode *right;

  // Yes this is a constructor
  treenode(T data): data(data){ // Part after : call data constructor
    this->data = T(data);
    left = NULL;
    right = NULL;
  }
};


template <class N>
class bst{
private:
  typedef treenode<N> node;
  node *root;

  void insert(N data, node **cursor){
    if (*cursor==NULL){
      *cursor = new node(data); // Constructor is called!
    }
    else{
      if (data < (*cursor)->data)
        insert(data, &(*cursor)->left);
      else
        insert(data, &(*cursor)->right);
    }
  }

  node *search(N key, node *cursor){
    if (cursor==NULL) // Item not found 
      return NULL;
    else if (key==cursor->data) 
      return cursor;
    else if (key < cursor->data)
      return search(key, cursor->left);
    else
      return search(key, cursor->right);
  }
  
  void inorder(node *cursor){
    if (cursor == NULL)
      return;
    inorder(cursor->left);
    cout << "(Node: "<<cursor<<", Left: "<<cursor->left<<", Right: "<<cursor->right<<", "<<cursor->data << ")" <<endl;
    inorder(cursor->right);
      
  }

  int countnodes(node *cursor){
    if(cursor==NULL)
      return 0;
    else
      return 1 + countnodes(cursor->left) + countnodes(cursor->right);
  }

  void print(node *cursor, int depth){
    if (cursor == NULL)
      return;
    for (int i = 0; i < depth; i++)
      printf(i == depth - 1 ? "|-" : "  ");
    cout<<cursor->data << endl;
    print(cursor->left, depth + 1);
    print(cursor->right, depth + 1);
  }

  int height(node *cursor){
    int lh, rh; 
    if (cursor==NULL)
      return -1;
    else{
      lh = 1 + height(cursor->left);
      rh = 1 + height(cursor->right);
      return (lh > rh) ? lh : rh;
    }
  }

  void delete_tree(node *cursor){
    if (cursor==NULL)
      return; 
    delete_tree(cursor->left);
    delete_tree(cursor->right);
    delete cursor;
  }

  void vectorize(node *cursor, vector<N> &v){
    if (cursor==NULL)
      return; 
    vectorize(cursor->left, v);
    v.push_back(cursor->data);
    vectorize(cursor->right, v);
  }
  
  
public:
  bst(){
    root = NULL;
  }

  void insert(N data){
    insert(data, &root);
  }

  treenode<N> *search(N data){
    if (root==NULL)
      return NULL;
    else
      return search(data, root);
  }

  void inorder(){
    if (root==NULL)
      return;
    else
      inorder(root);
  }

  vector<N> *vectorize(){
    vector<N> *v = new vector<N>;
    vectorize(root, *v);
    return v;
  }

  int node_count(){
    return countnodes(root);
  }

  int height(){
    if (root==NULL)
      return -1;
    else
     return height(root);
  }

  void print(){
    if (root==NULL)
      return;
    else
      print(root, 0);
  }

  ~bst(){
    delete_tree(root);
  }
};
