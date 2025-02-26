# include<stdio.h>

void transpose(int *mat, int *tr_mat, int nr, int nc){
  for (int i=0; i < nr; i++)
    for (int j=0; j < nc ; j++)
      tr_mat[j*nr+i] = mat[i*nc+j];
}

void print_mat(int *mat, int nr, int nc){
  for (int i=0; i<nr; i++){
    for (int j=0; j<nc; j++)
      printf("%d", mat[i*nc +j]);
    printf("\n");
  }
  printf("\n");
}

int main(void){
  int a[2][3] = {{1,2,3},{4,5,6}};
  int t[3][2] = {0};

  print_mat((int *) a, 2, 3);
  transpose((int *) a ,(int *) t, 2, 3);
  print_mat((int *) t, 3, 2);

  return 0;
}
