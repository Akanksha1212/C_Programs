#include<stdio.h>

int twostacks[10],top1=-1,top2=10;

int push1(int);
int push2(int);
int pop1();
int pop2();
int display1();
int display2();

int main()
{
	int n,ch=1,x;
  while(ch==1)
  {
	printf("Enter your choice:\n");
	printf("1.Push in stack 1\n");
	printf("2.Push in stack 2\n");
	printf("3.Pop from stack 1\n");
	printf("4.Pop from stack 2\n");
	printf("5.Display stack 1\n");
	printf("6.Display stack 2\n");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1:
			printf("Enter the element:\n");
			scanf("%d",&x);
			push1(x);
			break;
		case 2:
			printf("Enter the element:\n");
			scanf("%d",&x);
			push2(x);
			break;
		case 3:
			pop1();
			break;
		case 4:
			pop2();
			break;
		case 5:
			display1();
			break;
		case 6:
			display2();
			break;
		default: printf("Wrong choice...");
	}
	printf("Do you want to continue(1/0):");
	scanf("%d",&ch);
}
	return 0;
}


int push1(int x)
{
	if(top1<top2-1)
	{
		top1++;
		twostacks[top1]=x;
	}
	else
	{
		printf("Overflow Stack 1\n");
	}
	return ;
}

int push2(int x)
{
	if(top1<top2-1)
	{
		top2--;
		twostacks[top2]=x;
	}
	else
	{
		printf("Overflow Stack 2\n");
	}
	return;
}

int pop1()
{
	if(top1==-1)
		printf("Empty stack 1\n");
	else
	{
		printf("Popped element:%d\n",twostacks[top1]);
		top1--;
	}
	return;
}

int pop2()
{
	if(top2==10)
		printf("Empty stack 2\n");
	else
	{
		printf("Popped element:%d\n",twostacks[top2]);
		top2++;
	}
	return;
}

int display1()
{
	int i;
	for(i=0;i<=top1;i++)
		printf("%d\t",twostacks[i]);
	printf("\n");
	return;
}

void display2()
{
	int i;
	for(i=9;i>=top2;i--)
		printf("%d\t",twostacks[i]);
	printf("\n");
	return;
}


