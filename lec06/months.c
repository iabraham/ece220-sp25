#include <stdio.h>


int main(void){
  int month_num;
  printf("Enter month number:\t");
  scanf("%d", &month_num);
  switch (month_num) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    printf("Month has 31 days!\n");
    break;
    case 4: case 6: case 9: case 11:
    printf("Month has 30 days!\n");
    break;
    case 2:
    printf("Month has 28 days!\n");
    break;
    default:
    printf("Invalid month!");

  }
  return 0;
}
