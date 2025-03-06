#include <stdio.h>
#include <time.h>

unsigned long long lookup[100];

// Recursive function with lookup table
unsigned long long fib_lookup(unsigned long long n){
if (lookup[n]!=-1)
    return lookup[n];
if (n<2)
    lookup[n] = n;
else
    lookup[n] = fib_lookup(n-1) + fib_lookup(n-2);
return lookup[n];
}

// Iterative function
unsigned long long fib_iter(long long n){
  long long tempf, fnow, fnext; 
  fnext=1; 
  fnow=0;
  do{
    tempf = fnow + fnext;
    fnow = fnext;
    fnext = tempf; 
    n--;
  }while (n>0);
  return fnext;
}

// Standard recursive function
unsigned long long fib(long long n){
  unsigned long long sum;

  if (n == 0 || n == 1)
    return 1;
  else {
    sum = (fib(n-1) + fib(n-2));
  return sum;
  }
}


int main(void){

  for (int i=0; i<100; i++)
    lookup[i]=-1;

  const int N = 35;
  clock_t t1, t2, t3;
  printf("Starting first trial\n");
  t1 = clock();
  long long fib1 = fib(N);
  t1 = clock() - t1;
  double time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
  printf("Recursive NAIVE fib(%d) took: %f seconds\n",N, time_taken);

  printf("Starting second trial\n");
  t2 = clock();
  long long fib2 = fib_lookup(N);
  t2 = clock() - t2;
  time_taken = ((double)t2)/CLOCKS_PER_SEC; // in seconds
  printf("Recursive LOOKUP fib(%d) took: %f seconds\n",N, time_taken);


  printf("\nStarting third trial\n");
  t1 = clock();
  fib1 = fib_iter(N+1);
  t1 = clock() - t1;
  time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
  printf("ITERative fib(%d) took: %f seconds\n",N+1, time_taken);

  printf("Starting fourth trial\n");
  t2 = clock();
  fib2 = fib_lookup(N+1);
  t2 = clock() - t2;
  time_taken = ((double)t2)/CLOCKS_PER_SEC; // in seconds
  printf("Recursive LOOKUP fib(%d) took: %f seconds\n",N+1, time_taken);
}
