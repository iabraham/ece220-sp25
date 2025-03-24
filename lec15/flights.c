#include <stdio.h>

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

  Flight flights[3] = {
    {"AA1234", 1000, 900, {40.7128, 74.0060}, {34.0522, 118.2437}},
    {"BA5678", 1200, 1100, {34.0522, 118.2437}, {40.7128, 74.0060}},
    {"LH9999", 1400, 1300, {40.7128, 74.0060}, {34.0522, 118.2437}}
  };
  FILE *outfile = fopen("myflights.bin", "wb");
  fwrite(flights, sizeof(flights[1]), 3,outfile);
  fclose(outfile);

  return 0;
}
