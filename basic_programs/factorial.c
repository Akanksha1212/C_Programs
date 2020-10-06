//Factorial of Numbers
#include"stdio.h"
int fact(int);
int main()
{
	int n;
	printf("Enter the number you want to calculate the factorial-->\n");
	scanf("%d",&n);
	fact(n);
	printf("The factorial of the entered number is %d\n",fact(n));
	return 0;	
}
int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}
