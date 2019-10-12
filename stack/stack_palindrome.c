#include<stdio.h>
#include<stdlib.h>
# define max 4
int stack[max],item;
int ch, top=-1,status=0;
void push(int stack[],int item)
{
	if(top==(max-1))
		printf("\nstack is overflow");
	else
	{
		stack[++top]=item;
		status++;
	}
	
}
int pop(int stack[])
{
	int ret;
	if(top==-1)
		printf("\n stack is underflow");
	else
	{
		ret=stack[top--];
		status--;
		printf("\n popped elemnt is %d",ret);
	}
return ret;
}
void palindrome(int stack[])
{
	int i,temp,count=0;
	status=temp;
	for(i=0;i<temp;i++)
	{	
		if(stack[i]==pop(stack))
			count++;
	}
if(temp==count)
	printf("\n stack contents are palindrome");
else
	printf("\n stack contents are not palindrome");
}
void display(int stack[])
{
	int i;
	if(top==-1)
		printf("\nthe stack is empty");
	else
	{
		printf("\n the stack contents are:");
		for(i=top;i>=0;i--)
		printf("\n.....\n|%d|",stack[i]);
	}
}
void main()
{
	do
	{	
		printf("\nMAIN MENU\n");
		printf("\n1.push in the stack");
		printf("\n2.pop from the stack");
		printf("\n3.palindrome check using stack");
		printf("\n4.exit");
		printf("entre your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n enter element to be pushed\n");
			       scanf("%d",&item);
				push(stack,item);
				display(stack);
				break;
			case 2:pop(stack);
				display(stack);
				break;
			case 3:palindrome(stack);
				break;
			case 4:exit(0);
				break;
			default:printf("\n enter a valid choice\n");
		}

	}
while(ch!=4);
}

				






















	
