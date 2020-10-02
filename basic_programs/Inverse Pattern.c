/* 
Enter the number:7
*******
******
*****
****
***
**
*

*/

#include<stdio.h>
int main(){
	int i,j,n;	
	printf("Enter the number:");		
	scanf("%d",&n);														
	for(i=1;i<=n;i++)												
	{
		for(j=i;j<=n;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
