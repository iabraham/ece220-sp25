#include <stdio.h>

#define N 10 // Number of sticks allowed
#define M 3  // Types of lengths

// Lengths: 3 feet, 7 feet and 10 feet
const int set[M] = {3, 7, 10}; 

// Implement this function 
// solution[N]: stores the solution
// idx: index for the solution matrix
// total: remaining length
int solve(int solution[N], int idx, int total){
}


int main(){
  int solution[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int total, found;
  printf("Enter total length: ");
  scanf("%d", &total);
  found = solve(solution, 0, total);
  if (found)
	  for (int i=0; i<N; i++)
      printf("%d\t ", solution[i]);
  else
    printf("No solution exists");
}

