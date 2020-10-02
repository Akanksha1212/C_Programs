/* 
Enter the Number:7
------
-----*
----**
---***
--****
-*****
******

*/


# include<stdio.h>
int main(){
	
	int i,j,k,n;
	printf("Enter the Number:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		// prints spaces 
		for(j=i;j<n;j++)
		{
			printf("-");
			
		}
		// prints stars 
		for(k=1;k<i;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
