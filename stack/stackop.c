/*Author: Jithin Jose
 *GitHub: defaultRectr0
 *stack operations using arrays
*/
#include<stdio.h>
#include<stdlib.h>
int i,choice,check,num,top=-1,stack[100];
void push()
{
	if(top>=check-1)
	{
		printf("\n\tSTACK is full");
	}
	else
	{
		printf("Enter the value to be Pushed: ");
		scanf("%d",&num);
		top++;
		stack[top]=num;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("\nThe stack is Empty");
	}
	else
	{
		printf("\nThe poped elements is %d ",stack[top]);
		top--;

	}
}
void display()
{
	if(top>=0)
	{
		printf("\nThe elements is in the STACK : ");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
	}
	else
	{
		printf("\nThe stack is empty");
	}
	
}
void main()
{
	printf("Enter the size of STACK[MAX=100] : ");
	scanf("%d",&check);
	printf("\n\t1.PUSH\n\t2.PULL\n\t3.DISPLAY\n\t4.EXIT\n");
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	push();
					break;
			case 2:	pop();
					break;
			case 3:	display();
					break;
			case 4:	printf("\n\t-------Exiting--------\n");
					exit(0);
					break;
			default:	printf("Enter a valid choice");
		}
	}
	while(choice!=4);
}
