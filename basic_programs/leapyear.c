#include <stdio.h>
int main()
{
	int a;
	printf("Enter a year you want to check whether it is a leap year or not\n");
	scanf("%d",&a);

	if(a%100==0)
	{
		if(a%400==0)
		    printf("This is a leap year\n");
	    else
		    printf("This is not a leap year\n");
	}
	else
	{
		if(a%4==0)
		    printf("This is a leap year\n");
	    if(a%4!=0)
	        printf("This is not a leap year\n");
	}
	return 0;
}
