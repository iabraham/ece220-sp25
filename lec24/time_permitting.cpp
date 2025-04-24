#include <iostream>
#include <list>

/* Code example thanks to Dr. Thomas Moon */ 

using namespace std;
class A{
   private:
       list<int*> data;

   public:
       A(list<int*> data_){data=data_;}
       list<int*> getData(){return data;}
};

int main(){
   list<int*> temp;
   temp.push_back(new int(1));
   temp.push_back(new int(2));
   temp.push_back(new int(3));
   temp.push_back(new int(4));

   A a(temp);

   list<int*>::iterator it;

  // Snippet 1
   cout<<(a.getData()).size()<<endl;  // Comment this to make it run
   for (it = (a.getData()).begin(); it != (a.getData()).end(); it++) // Comment this to make it run
       cout << *(*it) << endl; // Comment this to make it run 

  // Snippet 2
   list<int*> mylist = a.getData();
   for (it = mylist.begin(); it != mylist.end(); it++)
       cout << *(*it) << endl;

  // Why do the snippets behave differently?
  //
  // CHALLENGE: fix the whole code by adding/removing/replacing a SINGLE character in a SINGLE position.
}
