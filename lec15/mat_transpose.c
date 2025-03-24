#include <stdio.h>



int main(void){
  FILE *infile = fopen("mat.csv", "r");
  FILE *outfile = fopen("t_mat.csv", "w");
  int i, j;
  int nr, nc; 

  int mat[50][50]={-1};

  fscanf(infile, "%d, %d", &nr, &nc);
  for (i=0; i<nr; i++){
    for (j=0; j<nc; j++){
      fscanf(infile, "%d, ", &mat[i][j]);
    }
  }
  fclose(infile);

  fprintf(outfile, "%d, %d\n", nc, nr);

  for (i=0; i<nc; i++){
    for(j=0; j<nr; j++){
      fprintf(outfile, "%d, ",mat[j][i]);
    }
    fprintf(outfile,"\n");
  }

  fclose(outfile);
  return 0;
}
