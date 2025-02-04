#include<stdio.h>

int itsGlobal = 0;

int main(){
/* local to main */ 
int itsLocal = 1; 
printf("Global %d Local %d\n", itsGlobal, itsLocal);

{
/* local to this block */
int itsLocal = 2;
/* change global variable */     
itsGlobal = 4;     
     printf("Global %d Local %d\n", itsGlobal, itsLocal);
}
printf("Global %d Local %d\n", itsGlobal, itsLocal); 
return 0;
} 
