#include <stdio.h>


void move(int disknum, int src, int dest, int temp){
  if (disknum > 1){
    move(disknum - 1, src, temp, dest);
  
    printf("Moved disk %d from rod %d to %d\n", disknum, src, dest);

    move(disknum - 1, temp, dest, src); 
  }
  else
  printf("Moved disk 1 from rod %d to %d\n", src, dest);
}


int main(void){

  move(4, 1, 3, 2);

  return 0;
}
