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
    fclose(file); // File exists, so close it
    return 1;     // Return true 
  }
  return 0;       // Return false
}

int make_data(char *filename, Flight *array, int numplanes){
  if (!exists(filename)){
    FILE *outfile = fopen(filename, "wb");
    fwrite(&numplanes, sizeof(int), 1, outfile);
    fwrite(array, sizeof(Flight), numplanes, outfile);
    return fclose(outfile); 
  }
  else{
    return -1;
  }
}

int load_data(char *filename, Flight *array){
  int numplanes; 
  FILE *infile; 
  if (!exists(filename)){
    return -1;
  }
  else{
    infile = fopen(filename, "rb");
    fread(&numplanes, sizeof(int), 1, infile);
    fread(array, sizeof(Flight), numplanes, infile);
    return numplanes;
  }
}

int main(void){

//   Flight flights[5] = {
//     {"AA1234", 1000, 900, {40.7128, 74.0060}, {34.0522, 118.2422}},
//     {"BA5678", 1200, 1100, {74.0522, 28.2437}, {40.7128, 26.2600}},
//     {"LH9999", 1400, 1300, {40.7128, 74.0060}, {34.0522, 118.2437}},
//     {"QF8888", 1600, 1500, {34.0522, 18.2437}, {40.7128, 74.0060}},
//     {"SA7777", 1800, 1700, {40.7128, 74.0060}, {34.0522, 118.2437}}
//   };
// 
//   make_data("flights.dat", flights, 5);
  //
  Flight flights[50];
  int numplanes = load_data("flights.dat", flights);

  for (int i = 0; i < numplanes; i++){
    printf("Flight %s from (%f, %f) to (%f, %f)\n", flights[i].code,
           flights[i].origin.lattitude, flights[i].origin.longitude,
           flights[i].destination.lattitude, flights[i].destination.longitude);
  }

  return 0;
}
