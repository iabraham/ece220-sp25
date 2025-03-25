#include <stdio.h>


typedef enum weekday {SUN=1, MON=4, TUE=7, WED, THR, FRI, SAT} weekday;

int is_workday(weekday day){
  if (day>SUN && day<SAT)
    return 1;
  else
    return 0;
}

int main(void){

  weekday today=THR;
  weekday day_after_next = today+2;

  printf("Today is day #%d of the week.\n", today);
  printf("Today is %s\n", is_workday(today) ? "a workday" : "not a workday");

  printf("\n");
  printf("Day after tomorrow is day #%d of the week.\n", day_after_next);
  printf("That day is %s\n", 
          is_workday(day_after_next) ? "a workday" : "not a workday");
}
