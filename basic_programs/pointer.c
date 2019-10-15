#include <stdio.h>

void main(){
	int n;
	int *ptr;
	printf("what is your number : ");
	scanf("%d" , &n);
	ptr = &n;

	printf("your number : %d" , *(ptr));
}