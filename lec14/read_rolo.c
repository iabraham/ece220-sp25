#include <stdio.h>


int main(void){
  FILE *infile = fopen("rolodex.txt", "r");

  char name[20];
  char desc[20];
  int status;
  printf("Rolodex contains:\n");
  printf("===============\n");
  do{
    status = fscanf(infile, "%[^,], %s\n", name, desc);
    printf("Name: %s\n", name);
    printf("Description: %s\n", desc);
    printf("\n");
  }while(status != EOF);

  fclose(infile);
  return 0;
}
