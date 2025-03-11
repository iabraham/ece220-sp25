#include <stdio.h>


int main(void){

  int N = 3;
  char name[20];
  char desc[100];

  FILE *outfile=fopen("rolodex.txt", "w");

  do{
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter a description: ");
    scanf("%s", desc);

    fputs(name, outfile);
    fputs(", ", outfile);
    fputs(desc, outfile);
    fputs("\n", outfile);

    printf("\n");
    N--; 
  }while(N);
  fclose(outfile);
   return 0;
}
