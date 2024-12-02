#include<stdio.h>
#include<stdlib.h>

void printmatrix(int **a,int n,int m,int i)
{
	if(n-i>0)
	{
		int x,y;
		for(x=i;x<m-i;x++)
		{
			for(y=i;y<m-i;y++)
			{
				if(x==i||y==i||x==m-i-1||y==m-i-1)
				{
					a[x][y] =n-i;
				}
			}
		}
		printmatrix(a,n,m,i+1);
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	int m=2*n-1;
	int i,j;
	int **a = malloc(sizeof(int *)*m);
	for(i=0;i<m;i++)
	{
		a[i]=malloc(sizeof(int)*m);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]=0;
		}
	}
	
	printmatrix(a,n,m,0);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
