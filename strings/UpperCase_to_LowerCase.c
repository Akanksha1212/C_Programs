#include<stdio.h>
#include<string.h>

void main()
{ 
	/*This array can hold only upto 60 characters,
	 * if you want to enter more than this 
	 * you can modify it according to your will. */ 
	char ch[60];
	int i;
	
	printf("Enter a string:");
	gets(ch);
	
	for(i=0;i<=strlen(ch);i++)
	{
		if(ch[i]>=65 && ch[i]<=90)
		{
			ch[i]=ch[i]+32;
		}
	}
	
	printf("\n Lower Case String is: %s",ch);
	getch();
}
