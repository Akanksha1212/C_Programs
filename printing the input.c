#include<stdio.h>
main()
{
	int i,n,j[200];
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%d",&j[i]);
	}
	while(i<=n)
	{
		printf("%d",j[i]);
	}
}
