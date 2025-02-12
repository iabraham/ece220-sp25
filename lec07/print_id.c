#include <stdio.h>

void print_id(int n, char t){
  int i, j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if (i==j){
        printf("1 ");
      }
      else if(t=='l'){
        if(i>j){
          printf("0 ");
        }
      }
      else if(t=='u'){
        if (i<j){
          printf("0 ");
        }
        else{
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

int main(void){
  int n;
  char c; 
  int i, j;
  printf("Enter a positive integer: \t");
  scanf("%d", &n);
  printf("Enter upper (u) or lower (l):\t");
  scanf(" %c", &c);

  if (n>=1 && n<=8 && (c=='u' || c=='l')){
    print_id(n, c);
  }
  else {
  printf("Enter a number between 1-8 and char that is 'l' or 'u' please. Exiting...");
  }
}
