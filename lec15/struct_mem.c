#include <stdio.h>

struct student{
    char name[73];
    unsigned long UIN;
    unsigned int year;
    float GPA;
};


int main(void){

  struct student s1 = {"Garfield", 123456, 6, 3.5};
  struct student BL3[2] = {s1, {"Scooby", 234578164, 2, 4.0}};
  printf("The name is %s\n", BL3[1].name);
  BL3[1].GPA = 2.0;
  printf("GPA is %f\n", BL3[1].GPA);
  printf("I occupy %lu bytes", sizeof(s1));

  return 0;
}
