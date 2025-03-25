#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *infile = fopen("matrix.csv", "r");
  FILE *outfile = fopen("matrix_tr.csv", "w");

  int nr, nc, i, j;
  fscanf(infile, "%d, %d", &nr, &nc);

  // IMPORTANT: Note we are allocating nr x size of int-pointer, not int!!
  // This was the mistake I made in the class
  int **mat = (int **) malloc(sizeof(int *)*nr);

  for(i=0; i<nr; i++){
    mat[i] = (int *) malloc(sizeof(int)*nc);
  }

  for(int i=0; i<nr; i++)
    for(int j=0;j<nc; j++)
      fscanf(infile, "%d,", &mat[i][j]);

  fclose(infile);

  fprintf(outfile, "%d, %d\n", nc, nr);

  for (j=0; j<nc; j++){
    for(i=0; i<nr; i++){
      fprintf(outfile, "%d, ", mat[i][j]);
    }
    fprintf(outfile, "\n");
  }

  fclose(outfile);

  for(i=0;i<nr;i++)
    free(mat[i]);
  free(mat);

  return 0;

}
