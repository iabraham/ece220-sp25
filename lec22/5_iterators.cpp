#include<iostream> 
#include<iterator> // for iterators 
#include<vector>   // for vectors 

using namespace std; 

int main() { 
    vector<int> ar = { 1, 2, 3, 4, 5 }; 
    vector<char> cr = {'E', 'C', 'E', '2', '2', '0'};
//    vector<char>::iterator ptr;     // Declaring iterator to a vector

    cout << "The vector elements are : "; 
    for (auto ptr = cr.begin(); ptr < cr.end(); ptr++)
        cout << *ptr << " "; 

    return 0;	 
}
