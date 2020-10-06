#include<stdio.h>
int p,q,grid[100][100];

#define minval(a,b,c) (a<b)?((a<c)?a:c):((b<c)?b:c)
#define min(a,b) (a,b)?a:b

int mincost(int m,int n)
{
	int dp[100][100];
	int i,j;
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			dp[i][j]=0;
	dp[0][0]=grid[0][0];
	for(i=1;i<p;i++)
		dp[i][0]=dp[i-1][0]+grid[i][0];
	for(j=1;j<q;j++)
		dp[0][j]=dp[0][j-1]+grid[0][j];
	for(i=1;i<p;i++)
	{
		for(j=1;j<q;j++)
		{
			
				dp[i][j]=minval(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
				dp[i][j]+=grid[i][j];	
		}
	}
	return dp[m][n];
}

int main()
{
	int m,n,i,j;
	printf("Enter the no.of rows and columns:");
	scanf("%d%d",&p,&q);
	printf("Enter the cost in the grid:");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&grid[i][j]);
	printf("Enter the position:\n");
	scanf("%d%d",&m,&n);
        if(m > (p-1) || n > (q-1))
        printf("invalid postion");

        else
	printf("%d",mincost(m,n));
	return 0;
}
