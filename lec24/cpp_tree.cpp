#include <iostream>
#include "bst.hpp"

using namespace std;

int main(){
  bst <int> tree1;
  cout<<"Building a Binary Search Tree"<<endl;

  tree1.insert(45);
  tree1.insert(50);
  tree1.insert(35);
  tree1.insert(30);
  tree1.insert(70);
  tree1.insert(20);
  tree1.insert(40);
  tree1.insert(80);
  tree1.insert(60);

  cout<<"Total number of nodes in this tree: ";
  cout<<tree1.node_count()<<endl;
  tree1.inorder();

  cout<<endl;
  tree1.print();
  cout<<"The tree height is: "<<tree1.height();

  vector <int> *v = tree1.vectorize();
  cout<<endl<<"Vectorized in order this is:"<<endl;
  for (auto it= v->begin(); it != v->end(); ++it)
  	  cout<<*it<<", ";
  cout<<endl;

  cout<<"70 lives at address:\t"<<tree1.search(70)<<endl;

  delete v;
  return 0;
  }

