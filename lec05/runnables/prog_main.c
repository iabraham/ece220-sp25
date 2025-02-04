/* This is prog_main.c */

#include <stdio.h>

void foo(int my_num);

int main(void){
	extern int a;
	int a_value = 10;
	printf("Main value is: %d\n", a_value);
	printf("Now calling foo with %d \n", ++a_value);
	foo(a_value);
	printf("Value of a is: %d\n", a);
}
