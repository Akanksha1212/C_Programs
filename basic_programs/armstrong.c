#include <stdio.h>
int main(void)
{
	//This program takes a three digit number and checks 
	//if it is armstrong number or not
	//Armstrong number of three digit is number whose sum 
	//of cubes of digits is equal to number itself	
    int number, originalNumber, remainder, result = 0;
    printf("Enter a three digit integer: ");
    scanf("%d", &number);
    originalNumber = number;
    while (originalNumber != 0)
    {
        remainder = originalNumber%10;
        result += remainder*remainder*remainder;
        originalNumber /= 10;
    }
    if(result == number)
        printf("%d is an Armstrong number.",number);
    else
        printf("%d is not an Armstrong number.",number);
    return 0;
}


