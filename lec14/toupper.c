#include <stdio.h>


int main(void){

  FILE *infile, *outfile; 

  infile = fopen("lower.txt", "r");
  outfile = fopen("upper.txt", "w");

  char curr; 

  while((curr=fgetc(infile))!=EOF){
    if (curr>=97 && curr<=122)
      curr = curr - 32;
    fputc(curr, outfile);
  }

  fclose(infile);
  fclose(outfile);

  return 0;
}
