#include <stdio.h>

int main(void){
  int area_code, prefix, pnum; 
  char mystr[13];
  
printf("Enter a 10-digit phone number.\n");
  printf("Format: xxx-xxx-xxxx\n");
  
fgets(mystr, 13, stdin);
  sscanf(mystr, "%d-%d-%d", &area_code, &prefix, &pnum);
  
printf("\nArea code: %d", area_code);
  printf("\nPrefix: %d", prefix); 
  printf("\nLocal: %d", pnum);

  return 0;
}
