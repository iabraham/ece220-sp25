#include <stdio.h>
#include <time.h>

// Recursive function to find the nth Fibonacci number
unsigned long long fib(long long n){
  unsigned long long sum;

  if (n == 0 || n == 1)
    return 1;
  else {
    sum = (fib(n-1) + fib(n-2));
  return sum;
  }
}

// Iterative function to find the nth Fibonacci number
unsigned long long fib_iter(long long n){
  long long fnow = 0; 
  long long fnext = 1; 
  long long temp; 
  do{
    n--;
    temp = fnow + fnext; 
    fnow = fnext;
    fnext = temp; 
  }
  while(n>0);
  return fnext;
}

int main(void){

  clock_t t1, t2;
  printf("Starting first trial\n");
  t1 = clock();
  long long fib1 = fib(20);
  t1 = clock() - t1;
  double time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
  printf("Recursive fib took: %f seconds\n", time_taken);
  printf("Fib of 20 was %lld \n", fib1);

  printf("Starting second trial\n");
  t2 = clock();
  long long fib2 = fib_iter(20);
  t2 = clock() - t2;
  time_taken = ((double)t2)/CLOCKS_PER_SEC; // in seconds
  printf("Iterative fib took: %f seconds\n", time_taken);
  printf("Fib of 20 was %lld \n", fib2);
}
