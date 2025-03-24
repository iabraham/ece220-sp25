#include <stdio.h>



int main(void){
  FILE *infile = fopen("records.tsv", "r");
  FILE *outfile = fopen("transposed.tsv", "w");
  int i, j;
  int nr, nc; 
  char data[15][20]; // First dimension should be atleast nr x nc !

  fscanf(infile, "%d %d", &nr, &nc);
  for (i=0; i<nr; i++){
    for (j=0; j<nc; j++){
      fscanf(infile, "%s", data[i*nc+j]);
    }
  }
  fclose(infile);

  fprintf(outfile, "%d\t%d\n", nc, nr);
  for (j=0; j<nc; j++){
    for(i=0; i<nr; i++){
      fprintf(outfile, "%s\t",data[i*nc+j]);
    }
    fprintf(outfile,"\n");
  }

  fclose(outfile);
  return 0;
}
