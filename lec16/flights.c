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

/* Function to check if file exists on disk  */
int exists(const char *filename){
  FILE *file = fopen(filename, "r");
  if (file){
    fclose(file);
    return 1;
  }
  return 0;
}

int make_data(char *filename, int numplanes){

}

int load_data(char *filename, int numplanes, Flight *array){

}

int main(void){

  Flight flights[5] = {
    {"AA1234", 1000, 900, {40.7128, 74.0060}, {34.0522, 118.2422}},
    {"BA5678", 1200, 1100, {74.0522, 28.2437}, {40.7128, 26260060}},
    {"LH9999", 1400, 1300, {40.7128, 74.0060}, {34.0522, 118.2437}},
    {"QF8888", 1600, 1500, {34.0522, 18.2437}, {40.7128, 74.0060}},
    {"SA7777", 1800, 1700, {40.7128, 74.0060}, {34.0522, 118.2437}}
  };
  

  FILE *outfile = fopen("myflights.bin", "wb");
  fwrite(flights, sizeof(flights[1]), 3,outfile);
  fclose(outfile);

  return 0;
}
