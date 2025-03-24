#include<stdio.h>

typedef struct geoloc{
  float lattitude; 
  float longitude; 
} geo;


typedef struct flight{
  char code[8];
  unsigned int arrival_time;
  unsigned int depart_time; 
  geo origin; 
  geo destination; 
} Flight;



int main(void){
  Flight flights[10];

  FILE *infile = fopen("myflights.bin", "rb");

  if(infile == NULL){
    printf("no such file!");
    return 1;
  }
  else{
    fread(flights, sizeof(flights[0]), 3, infile);
  }

  for (int i=0; i<3; i++){
    printf("Flight %d\n", i+1);
    printf("Code: %s\n", flights[i].code);
    printf("============");
  }

  return 0;
}
