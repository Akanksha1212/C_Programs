#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 100
int a[max];
int n=-1;
void push(int data)
{
    if(n==max)
    {
        printf("Overflow");
    }
    else
    {
        a[++n]=data;
}
}
int pop()
{
    if(n==-1)
    {
        printf("Underflow");
        return INT_MIN;
    }
    else
    {
        int temp = a[n];
        n--;
        return temp;
    }
}
int peek()
{
    if(n==-1)
    {
        printf("Underflow");
        return INT_MIN;
    }
    else
    {
        return a[n];
    }
}
void print()
{
    for(int k=0;k<=n;k++)
    {
        printf("%d ",a[k]);
    }

}
int main()
{
    for(int j=0;j<max;j++)
        a[j]=0;
    int i=1;
    n=-1;
    while(i!=0)
    {
    printf("Enter the operation \n1)push\n2)pop\n3)peek\n4)print\n0)Exit\n");
    scanf("%d",&i);
    if(i==1)
    {
        int data;
        printf("Enter data\n");
        scanf("%d",&data);
        push(data);
    }
    else if(i==2)
    {
        int temp = pop();
        if(temp!=INT_MIN)
        printf("%d\n",temp);
    }
    else if(i==3)
    {
        int temp = peek();
        if(temp!=INT_MIN)
            printf("%d\n",temp);
    }
    else if(i==4)
    {
        print();
        printf("\n");
    }
    else if(i==0)
    {
        break;
    }
    }
}
