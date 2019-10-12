#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;
void push(char c)
{
	
	stack[++top]=c;
}
char pop()
{
	char c;
	c=stack[top--];
	return c;
}
char peek()
{
	return stack[top];
}

int ispri(char c)
{
	switch(c)
	{
		case '+':return 2;
		case '-':return 1;
		case '*':return 4;
		case '/':return 3;
		case '^':return 5;
	}
}

void func(char ch[])
{
	char exp[50];
	int ctr=0;
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]=='(')
		{
			push(ch[i]);
		}
		else if((ch[i]>='a' && ch[i]<='z')||(ch[i]>='A'&& ch[i]<='Z'))
		{
			exp[ctr++]=ch[i];
		}
		else if(ch[i]==')')
		{
			while(peek()!='(')
				exp[ctr++]=pop();
			pop();
		}
		else
		{
			if(ispri(ch[i])<=ispri(stack[top]) && stack[top]!='(')
			{
				exp[ctr++]=pop();
				push(ch[i]);
			}
			else
				push(ch[i]);
			
		}	
	}
	exp[ctr]='\0';
	puts(exp);	
}

int main()
{
	char ch[50];
	printf("Enter any expression in braces():");
	scanf("%s",ch);
	func(ch);
}
