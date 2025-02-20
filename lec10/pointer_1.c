#include <stdio.h>

int main(){
	int *arrp;
	int (*arrpw)[5];
	int arr[5]={5,2,3,1,4};

	arrp = arr;
	arrpw = &arr;

	printf("arrp= %p, arrpw= %p\n", arrp, arrpw);
	arrp++;
	arrpw++;
	printf("arrp= %p, arrpw= %p\n", arrp, arrpw);
}
