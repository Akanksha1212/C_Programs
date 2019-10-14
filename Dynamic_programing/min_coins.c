#include<stdio.h>
#define min(a,b) (a<b)?a:b
#define INF 1000000000

int mincoin(int coins[], int m, int V)
{
    
    int table[V+1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INF;
 
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INF && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}
int main()
{
	int n,coins[100],val;
	int i,j,res;
	printf("Enter the no. of coins:");
	scanf("%d",&n);
	printf("Enter the coins:");
	for(i=0;i<n;i++)
		scanf("%d",&coins[i]);
	printf("What is the final value ?:");
	scanf("%d",&val);
	res=mincoin(coins,n,val);
	printf("Minimum coins:%d\n",res);
	return 0;
}
