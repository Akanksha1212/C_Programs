//WAP to calculate SI , given P,R,T
#include <stdio.h>
#include <conio.h>

int main()
{
	float p,r,t,SI;
	printf("Enter the Principal amount: ");
	scanf("%f",&p);
	printf("Enter the Rate Of Interest: ");
	scanf("%f",&r);
	printf("Enter the Duration: ");
	scanf("%f",&t);
	SI=(p*r*t)/100;
	printf("\nThe Simple interest is: %f ",SI);
	getch();
	return 0;
}
