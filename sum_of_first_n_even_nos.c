#include<stdio.h>
int sum(int);

int main()
{
    int n;
    printf("Enter a no:=");
    scanf("%d",&n);
    printf("The sum of first 'n' even no.s is %d",sum(n));
    return 0;
}

int sum(int n)
{
    if(n==0)
    return 0;
    else
    return(sum(n-1)+2*(n-1));
} 
