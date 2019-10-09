#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 100
int a[max];
int f=-1,r=-1;
void enqueue(int data)
{
    if(r==max)
    {
        printf("Overflow");
    }
    else
    {
        if(r==-1)
            f=0;
        a[++r]=data;
}
}
int dequeue()
{
    if(f>r||f==-1)
    {
        printf("Underflow");
        return INT_MIN;
    }
    else
    {
        int temp = a[f];
        f++;
        return temp;
    }
}
void print()
{
    for(int k=f;k<=r;k++)
    {
        printf("%d ",a[k]);
    }
    
}
int main()
{
    for(int j=0;j<max;j++)
        a[j]=0;
    int i=1;
    while(i!=0)
    {
    printf("Enter the operation \n1)enqueue\n2)dequeue\n3)print\n0)Exit\n");
    scanf("%d",&i);
    if(i==1)
    {
        int data;
        printf("Enter data\n");
        scanf("%d",&data);
        enqueue(data);
    }
    else if(i==2)
    {
        int temp = dequeue();
        if(temp!=INT_MIN)
        printf("%d",temp);
    }
    else if(i==3)
    {
        print();
    }
    else if(i==0)
    {
        break;
    }
    }
}