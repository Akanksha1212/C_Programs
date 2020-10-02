/*
Enter the Number: 9
1
22
333
4444
55555
666666
7777777
88888888
999999999
*/

# include<stdio.h>

int main(){
	
	int i,j,n;
	printf("Enter the Number: ");
	scanf("%d",&n);
	// Print pattern for i
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",i);
		}
		printf("\n");
	}
}

