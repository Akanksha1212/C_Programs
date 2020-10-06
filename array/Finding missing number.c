// o(1) code to find the missing number in an array of 1 to N numbers

#include<stdio.h>

void main()
{
	int n;
	printf("Enter the total no of numbers:");
	scanf("%d",&n);
	int a[n];
	printf("Enter 1 to %d by leaving one number",n);
	int i,sum=0;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	printf("%d is the missing number",n*(n+1)/2 - sum);
}
