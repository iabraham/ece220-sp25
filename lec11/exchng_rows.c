#include <stdio.h>

#define NROWS 3
#define NCOLS 4

void exchng_rows(int mat[NROWS][NCOLS], int r1, int r2){
  int i, temp;
  for (i=0;i<NCOLS;i++){
    temp = mat[r2][i];        // store bottom value
    mat[r2][i] = mat[r1][i];  // overwrite bottom value
    mat[r1][i]=temp;          // replace top value
  }

}

void print(int mat[NROWS][NCOLS]){
  int i, j;
  for (i=0; i<NROWS; i++){
    for (j=0; j<NCOLS; j++){
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

int main(void){
  int a[NROWS][NCOLS] = {{1,2,3,4},{4,5,6,7}, {1, 3, 4, 8}}; 
  print(a);
  exchng_rows(a, 0, 2);
  printf("=================\n");
  print(a);
  return 0;
}
