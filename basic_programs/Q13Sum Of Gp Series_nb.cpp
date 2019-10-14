//Sum of GP Series
#include <stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
	int n;
	printf("Enter the size of GP series: ");
	scanf("%d",&n);
	float ar[n];
	printf("Enter the GP series: ");
	for(int i=0;i<n;i++)
	{
		scanf("%f",&ar[i]);
	}
	float a=ar[0];
	float r=ar[1]/ar[0];
	//float x=float(n);
	float x=((a*(1-pow(r,n)))/1-r);
	if(r>=1)
		printf("Sum= %f",x);
	//else
		//printf("Sum= %f",(a*(1-r^x))/1-r);
	return 0;
}
