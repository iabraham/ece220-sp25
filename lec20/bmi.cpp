#include <iostream>


using std::cout; 
using std::cin; 

float bmi(float ht, float wt, bool si=false){
    float val = wt/(ht*ht);
    if (si)
        return val*10000;
    else
        return val*703;
}

int main(void){
  
  float ht, wt;
  int flag; 
  int *somarr = new int[5];

  cout<<"Enter height: "; 
  cin>>ht;
  cout<<"Enter weight: "; 
  cin>>wt;
  cout<<"European? (0/1): "; 
  cin>>flag; 

  if (flag==0){
    cout<<"BMI: "<<bmi(ht, wt)<<"\n";
  }
  else{
    cout<<"BMI: "<<bmi(ht, wt, true)<<"\n";
  }

  delete []somarr;

  return 0;
}
