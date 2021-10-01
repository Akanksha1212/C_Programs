#include<stdio.h>
int main()
{
 int n, i,j, a[100][100];
 int flag=0;
 printf("Enter Number of rows/columns:");
 scanf("%d",&n);
 printf("Enter values:");
 for (i=0;i<n;i++)
 {
 	for (j=0;j<n;j++)
 	{
 		scanf("%d", &a[i][j]);
	}
 }
 for (i=0;i<n;i++)
 {
 	for (j=0;j<n;j++)
 	{
 		if (a[i][j]!=0 && i!=j)
 		{
 			flag=1;
 			break;
		}
	}
 }
 if (flag==0) printf("Diagonal Matrix");
 else printf("Not Diagonal Matrix");
 return 0;
 }
