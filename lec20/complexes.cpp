#include<iostream>
using namespace std; 

class Complex{
  double real;
  double imag;

public:
  Complex(double real, double imag){
    this->real = real;
    this->imag = imag; 
  }

  void print(){
    cout<<"(" <<this->real<<" + "<<this->imag<<"j)";
  }

Complex operator+(Complex c){
    return Complex(this->real + c.real, this->imag + c.imag);
  }

Complex operator*(Complex y){
    double c = y.real; 
    double d = y.imag; 
    double a = this->real; 
    double b = this->real; 
    return Complex(a*c-b*d, a*d+b*c);
  }
};

int main(){
  Complex c1 = Complex(2, 4);
  Complex c2 = Complex(3, -5);
  cout<<"Complex 1: ";
  c1.print();
  cout<<endl<<"Complex 2: ";
  c2.print();
  Complex c3 = c1 + c2;
  cout<<endl<<"Sum: ";
  c3.print();
  Complex c4 = c1 * c2; 
  cout<<endl<<"Product: ";
  c4.print();

}
