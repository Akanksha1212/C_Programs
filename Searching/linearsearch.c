#include<stdio.h>

/*
    Time Complexity : O(N)
    Space Complexity : O(1)
*/

void main()
{
	float s=clock();
	int arr[100],c,search,n;
	printf("Enter the size of array");
	scanf("%d",&n);
	printf("Enter %d element in array",n);
	for(c=0;c<n;c++)
	{
		scanf("%d",&arr[c]);
	}
	printf("Enter the element to be search");
	scanf("%d",&search);
	for(c=0;c<n;c++)
	{
		if(arr[c]==search)
		{
			printf("\n Element %d found at position %d ",search,c+1);
			break;
		}
	}
	if (c == n)
	{
	printf("\n Element not found");
}
	float e=clock();
	float p;
	p=(e-s);
	printf("\n %f",s);
	printf("\n %f",e);
	printf("\n %f",p);
}
