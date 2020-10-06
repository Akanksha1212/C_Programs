#include <stdio.h>

void main(){
	char grade;

	printf("enter your grade : ");
	scanf("%c", &grade);

	switch(grade){
		case 'A':
			puts("good job!");
			break;
		case 'B':
			puts("good !");
			break;
		case 'C':
			puts("you have to learn more");
			break;
		default:
			puts("wrong input..");

	}
}