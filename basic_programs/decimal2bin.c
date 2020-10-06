//programe to print the binary of the entered number
#include"stdio.h"
int main()
{
	int bin[32];
	int x,n,i=0;
	printf("Enter the number in base 10\n");
	scanf("%d",&n);
	while(n>0)
	{
		bin[i] = n%2;
		n = n/2;
		i++;
	}
	for(x= i-1;x>=0; x--)
	{
		printf("%d",bin[x]);
	}
	return 0;
}
