#include <stdio.h>


int sqr(int x){
	return x*x; 
}

int cube3(void){
	return 27;
}

int sqrt25(){
	return 5;
}

int main(void){
	// Intended usage
	printf("The square of %d is %d\n", 14, sqr(14));
	printf("The cube of %d is %d\n", 3, cube3());
	printf("The sqrt of %d is %d\n", 25, sqrt25());
	
	// Atypical (not recommended) usage - generates warnings but will
	// compile 
	printf("The sqrt of %d is %d\n", 25, sqrt25(25));
	printf("The sqrt of %d is %d\n", 25, sqrt25(25, 32));

	// Will not compile if uncommented
        // printf("The cube of %d is %d\n", 3, cube3(3));
	
}
