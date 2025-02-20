#include <stdio.h>

int main(void){
  char mystr[10];
  char mychar;
  printf("Enter a string:\t");
  scanf("%s", mystr);
//  fgets(mystr, 10, stdin);
  printf("\nYou entered: %s", mystr);
  printf("\nEnter a character:\t");
  scanf(" %c", &mychar);
  printf("\nYou entered: %c\n", mychar);
  return 0;
}
