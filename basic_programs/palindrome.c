#include<stdio.h>
#include<string.h>

int main()
{
	char t[50],s[50];
	int i,j,l=0,e=0,z,len;
	scanf("%[^\n]s",t);       //input the string to be checked
	for(i=1;t[i]!='\0';i++)
	{}
		len=i;
	
	for(i=0;i<len;i++)    
	{
		
		if(t[i]==' ')
		{
			for(j=i;t[j]!='\0';j++)
			{
				t[j]=t[j+1];
				
			}
				e++;
		}
	}
	
	len=len-e;


	for(i=0;i<len;i++)
	{
		s[len-1-i]=t[i];
	}
	for(i=0;i<len;i++)
	{
		if(t[i]==s[i]) l++;
	}

	if(l==len) printf("yes\n");
	else printf("no\n");       //final answer i.e. if a string is a palindrome or not

	return 0;
}