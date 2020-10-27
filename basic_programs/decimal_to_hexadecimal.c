// C Program to convert decimal to hexadecimal

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,r=0,i=0,j;
	char arr[100];
	printf("Enter the no.\n");
	scanf("%d",&n);
	while(n!=0)
	{
		r=n%16;
		if(r<10)
		{
			arr[i]=(char)(r+48);
			i++;
		}
		else
		{
			arr[i]=(char)(r+55);
			i++;
		}
		n=n/16;
	}
	for(j=i-1;j>=0;j--)
		printf("%c",arr[j]);
}
