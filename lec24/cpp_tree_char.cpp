#include <iostream>
#include "bst.hpp"

using namespace std;

int main(){
  bst <char> tree1;
  cout<<"Building a Binary Search Tree"<<endl;

  tree1.insert('E');
  tree1.insert('C');
  tree1.insert('E');
  tree1.insert('2');
  tree1.insert('2');
  tree1.insert('0');
  tree1.insert('F');
  tree1.insert('T');
  tree1.insert('W');

  cout<<"Total number of nodes in this tree: ";
  cout<<tree1.node_count()<<endl;
  tree1.inorder();

  cout<<endl;
  tree1.print();
  cout<<"The tree height is: "<<tree1.height();

  vector <char> *v = tree1.vectorize();
  cout<<endl<<"Vectorized in order this is:"<<endl;
  for (auto it= v->begin(); it != v->end(); ++it)
  	  cout<<*it<<", ";

  cout<<endl;
  cout<<"0 lives at address: "<<tree1.search('0')<<endl;

  delete v;

  return 0;
}

