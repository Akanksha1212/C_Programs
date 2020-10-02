/* 
Enter the Number: 6
*
**
***
****
*****
******

 */
# include<stdio.h>

int main(){
	int i,j,n;
	printf("Enter the Number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

