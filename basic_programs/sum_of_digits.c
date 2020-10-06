// C program to find sum of digits of a number

#include <stdio.h>

int main()
{
    int n,s=0;
    scanf("%d",&n);
    while(n>0)
    {
        s=s+n%10;
        n=n/10;
    }
    printf("Sum of digits is %d",s);
}
