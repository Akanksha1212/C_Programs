#include<stdio.h>

int main(){
	int num1, num2;
	printf("Enter first number : ");
	scanf("%d", &num1);					// Taking the first number from the user as an input
	printf("Enter second number : ");
	scanf("%d", &num2);					// Taking the first number from the user as an input

	printf("SUM of the two numbers %d and %d : %d\n", num1, num2, num1+num2); // Printing out the sum directly to the user
															    // Here (+) operator can be replaced by [ submission(-), multiplication(*), division(/) and modules(%)]

	return 0;
}
