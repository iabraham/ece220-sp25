#include<stdio.h>

int main(void){
  fprintf(stdout, "Normal output1\n");
  fprintf(stdout, "Normal output2\n");
  fprintf(stderr, "Error1 \n");
  fprintf(stdout, "Normal output3\n");
  fprintf(stderr, "Warning1\n");
}
