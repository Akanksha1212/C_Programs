#include<stdio.h>
#include<stdlib.h>

void sort(int a[],int noe)
{
	int i,j;
	for(i=0;i<noe-1;i++)
	{
		for(j=0;j<noe-i-1;i++)
		{
			if(a[j]>a[j+1])
			{
				int z;
				z=a[j];
				a[j]=a[j+1];
				a[j+1]=z;
			}
		}
	}
}

int min(int x,int y)
{
	if(x>=y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

int fibsearch(int a[],int noe,int num)
{
	int fib1=1,fib2=0;
	int fibn=fib1+fib2;
	while(fibn<noe)
	{
		fib2=fib1;
		fib1=fibn;
		fibn=fib1+fib2;
	}
	int offset=0;
	while(fibn>1)
	{
		int i=min(fib2+offset,noe);
		if(a[i]<num)
		{
			offset+=fib2;
			fibn=fib1;
			fib2=fibn-fib2;
			fib1=fibn-fib2;
		}
		else if(a[i]>num)
		{
			fib1=fib1-fib2;
			fibn=fib2;
			fib2=fibn-fib1;
		}
		else
		{
			return i;
		}
	}
		return -1;
}

int main()
{
	int n,i,num,result;
	int a[100];
	printf("enter the number of elements in array\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,n);
	printf("array after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nenter element to be searched\n");
	scanf("%d",&num);
	result=fibsearch(a,n,num);
	if(result==-1)
	{
		printf("%d is not present\n",num);	
	}	
	else
	{
		printf("%d is present at %d position in the given array\n",num,result);
	}
}
